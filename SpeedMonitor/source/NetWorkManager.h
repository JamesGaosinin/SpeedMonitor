#pragma once
#include <atlstr.h>
#include <string>
#include <list>
#include <map>
#include <future>
#include <QString>
#include <QObject>
#include <QMutex>
#include "3Dcmd.h"
#include "PackData.h"

class IBusClient;
enum EnClientState;

class CNetWorkManager : public QObject
{
	Q_OBJECT

public:
	static CNetWorkManager* GetInstance();
	static void Release();
	//接收数据 客户机
	static void OnBusDataCallback(ClientPackData* pData, void* arg);
	std::map<std::string, IBusClient*> ConnectServers();
	void FutureCallBack(std::future<std::map<std::string, IBusClient*>>& future);
private:
	CNetWorkManager();
	~CNetWorkManager();
	CNetWorkManager(const CNetWorkManager& other);

private:
	void Init();
	std::list<std::string> ReadClientNum();

public:
	std::map<std::string, IBusClient*> m_mapClient;//网络(广播发送)
	std::list<std::string> m_lstClient;
	bool m_bClientStatus = true;
	static CNetWorkManager* m_pInstance;
};

