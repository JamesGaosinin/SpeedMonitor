#include "NetWorkManager.h"
#include <iostream>
#include <future>
#include <QDateTime>
#include <QApplication>
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <IBusClientv3.h>
#include "../include/CommonHeader.h"
#include "TrainManagement.h"

using namespace _3Dcmd;

CNetWorkManager* CNetWorkManager::m_pInstance = nullptr;

CNetWorkManager::CNetWorkManager()
{
	Init();// TODO
}

CNetWorkManager::CNetWorkManager(const CNetWorkManager& other)
{
}

void CNetWorkManager::Init()
{
	m_lstClient = ReadClientNum();
	std::future<std::map<std::string, IBusClient*>> future = std::async(&CNetWorkManager::ConnectServers, this);
	std::thread thread = std::thread(&CNetWorkManager::FutureCallBack, this, std::move(future));
	thread.detach();
}

std::list<std::string> CNetWorkManager::ReadClientNum()
{
	std::list<std::string> lstClient;
	QString strAppDir = QApplication::applicationDirPath();
	QString strFilePath = strAppDir + QString("/Config/BusClient.xml");

	QFile file(strFilePath);
	if (!file.exists())
	{
		return lstClient;
	}
	if (!file.open(QIODevice::ReadOnly))
	{
		return lstClient;
	}
	QDomDocument doc;
	if (!doc.setContent(&file))
	{
		return lstClient;
	}
	QDomElement rootEle = doc.documentElement();
	if (rootEle.isNull())
	{
		return lstClient;
	}
	QDomElement childEle = rootEle.firstChildElement("Client");
	while (!childEle.isNull())
	{
		QString strClient = childEle.attribute("id");
		std::string strClientName = strClient.toLocal8Bit().data();
		lstClient.push_back(strClientName);
		childEle = childEle.nextSiblingElement("Client");
	}
	file.close();
	return lstClient;
}

CNetWorkManager::~CNetWorkManager()
{
	auto itr = m_mapClient.begin();
	for (; itr != m_mapClient.end(); ++itr)
	{
		IBusClient* pClient = itr->second;
		if (nullptr != pClient)
		{
			///pClient->Stop();
			//ReleaseIBusClient(pClient);
		}
	}
}

CNetWorkManager* CNetWorkManager::GetInstance()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CNetWorkManager;
	}
	return m_pInstance;
}

void CNetWorkManager::Release()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void CNetWorkManager::OnBusDataCallback(ClientPackData* pData, void* arg)//接收数据
{
	if (nullptr == pData)
	{
		return;
	}

	CNetWorkManager* pSelf = (CNetWorkManager*)arg;
	if (pData->head.id == 0x51)//TOD信息
	{
		TCMD m_cmd;
		memcpy(&m_cmd, pData->data, sizeof(TCMD));
		if (m_cmd.nType == DT_GLB)//公里标
		{
			stRTGLBInfo m_3dDate;
			memset(&m_3dDate, 0, sizeof(stRTGLBInfo));
			memcpy(&m_3dDate, pData->data, sizeof(stRTGLBInfo));

			float f_sPeed = m_3dDate.speed*3.6;	// m/s->km/h
			TrainBasicInfo stInfo;
			stInfo.m_strDevicdNum = m_3dDate.strTranNum;
			stInfo.m_strTranSerialNum = m_3dDate.strTranNum;
			stInfo.m_strRailName = m_3dDate.strCurPath;
			stInfo.m_fSpeed = f_sPeed;
			stInfo.m_fAbsolutePosition = m_3dDate.tf;
			stInfo.m_lCurTime = QDateTime::currentDateTime().toTime_t();

			int nTranDir = 0;
			if (m_3dDate.des == 1)// 上行
			{
				stInfo.m_nUpOrDown = E_TRAIN_UP_DOWN_TYPE_UP;
			}
			else if (m_3dDate.des == 0)// 下行
			{
				stInfo.m_nUpOrDown = E_TRAIN_UP_DOWN_TYPE_DOWN;
			}

			TRAINMANAGEMENT.RecvTrainBasicData(stInfo);

			std::cout << stInfo.m_strDevicdNum.toLocal8Bit().data() << std::endl;
		}
	}

	if (pData->head.id == 0x23)//TOD信息
	{
		techer_head m_Type;
		memcpy(&m_Type, pData->data, sizeof(techer_head));
		if (techer_net_type::en_techer_net_shutdown == m_Type.net_type)
		{
			std::cout << "关机" << std::endl;
			system("shutdown /s /t 0");
		}
		else if (techer_net_type::en_techer_net_time == m_Type.net_type)
		{
			NET_TIMESYNC_MSG stClock;
			memcpy(&stClock, pData->data, sizeof(NET_TIMESYNC_MSG));

			SYSTEMTIME sysTime;
			sysTime.wYear = stClock.year;
			sysTime.wMonth = stClock.month;
			sysTime.wDay = stClock.day;
			sysTime.wHour = stClock.h;
			sysTime.wMinute = stClock.m;
			sysTime.wSecond = stClock.s;
			SetLocalTime(&sysTime);
		}
	}
}

std::map<std::string, IBusClient*> CNetWorkManager::ConnectServers()
{
	std::map<std::string, IBusClient*> mapRet;
	for each (std::string var in m_lstClient)
	{
		char err[255] = { 0 };
		const char* pClientName = var.c_str();
		IBusClient* pClient = CreateIBusClient(pClientName, err);
		if (pClient == nullptr)
		{
			continue;
		}
		pClient->SetDataCallback(OnBusDataCallback, this);
		pClient->Start();

		mapRet[var] = pClient;
	}

	return mapRet;
}

void CNetWorkManager::FutureCallBack(std::future<std::map<std::string, IBusClient*>>& future)
{
	std::chrono::system_clock::time_point point = std::chrono::system_clock::now();
	point += std::chrono::milliseconds(1000);
	future.wait_until(point);
	m_mapClient = future.get();
}
