#include "TrainManagement.h"
#include "TrainEntity.h"

CTrainManagement* CTrainManagement::m_pInstance = nullptr;

CTrainManagement::CTrainManagement()
{
}


CTrainManagement::~CTrainManagement()
{
	auto itr = m_mapTrainInfo.begin();
	while (itr != m_mapTrainInfo.end())
	{
		CTrainEntity* pTrainEntity = itr.value();
		if (nullptr != pTrainEntity)
		{
			delete pTrainEntity;
			pTrainEntity = nullptr;
		}

		itr++;
	}
}

CTrainManagement* CTrainManagement::GetInstance()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CTrainManagement;
	}

	return m_pInstance;
}

void CTrainManagement::Release()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void CTrainManagement::RecvTrainBasicData(const TrainBasicInfo& stInfo)
{
	QMutexLocker locker(&m_Mutex);
	CTrainEntity* pTrainEntity = nullptr;
	auto itr = m_mapTrainInfo.find(stInfo.m_strTranSerialNum);
	if (itr == m_mapTrainInfo.end())
	{
		// ´´½¨³µ
		pTrainEntity = new CTrainEntity;
		m_mapTrainInfo[stInfo.m_strTranSerialNum] = pTrainEntity;
		emit Sig_CreateTrain(stInfo.m_nUpOrDown, stInfo.m_strTranSerialNum);
	}
	else
	{
		pTrainEntity = itr.value();
		if (nullptr == pTrainEntity)
		{
			return;
		}
	}
	
	pTrainEntity->AddTrainInfo(stInfo);
}

QMap<QString, CTrainEntity*> CTrainManagement::GetTrainInfo()
{
	QMutexLocker locker(&m_Mutex);
	return m_mapTrainInfo;
}

CTrainEntity* CTrainManagement::GetTrainEntity(const QString& strDevName)
{
	auto itr = m_mapTrainInfo.find(strDevName);
	if (itr != m_mapTrainInfo.end())
	{
		return itr.value();
	}

	return nullptr;
}
