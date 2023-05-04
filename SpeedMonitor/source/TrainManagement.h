#pragma once
#include <QObject>
#include <QMap>
#include "../include/CommonHeader.h"
#include <QMutex>

class CTrainEntity;

class CTrainManagement : public QObject
{
	Q_OBJECT

public:
	CTrainManagement();
	~CTrainManagement();

public:
	static CTrainManagement* GetInstance();
	static void Release();

public:
	void Initalize(const QString& strGBLFile);
	void RecvTrainBasicData(const TrainBasicInfo& stInfo);
	QMap<QString, CTrainEntity*> GetTrainInfo();
	CTrainEntity* GetTrainEntity(const QString& strDevName);

signals:
	void Sig_CreateTrain(int nUpDownType, const QString& strDevName);

private:
	static CTrainManagement* m_pInstance;

private:
	QMutex m_Mutex;
	QMap<QString, CTrainEntity*> m_mapTrainInfo;	// 列车集合

};

#ifndef TRAINMANAGEMENT
#define TRAINMANAGEMENT (*CTrainManagement::GetInstance())
#endif // !TRAINMANAGEMENT


