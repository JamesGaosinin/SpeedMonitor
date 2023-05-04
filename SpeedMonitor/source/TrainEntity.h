#pragma once

#include <QString>
#include <QMutex>
#include <QList>
#include <QPoint>
#include <QDateTime>
#include <3Dcmd.h>
#include "../include/CommonHeader.h"
#include "Common.h"

using namespace _3Dcmd;

class CTrainEntity
{
public:
	CTrainEntity();
	~CTrainEntity();

public:
	void AddTrainInfo(const TrainBasicInfo& stInfo);
	QList<QPointF> GetHistoryInfo(E_TRAIN_UP_DOWN_TYPE eType);
	TrainBasicInfo GetCurTrainInfo();

	E_TRAIN_UP_DOWN_TYPE GetCurUpDpwnType();

private:
	void ClearHistoryInfo();

private:
	QMutex m_Mutex;

	QDateTime m_LastInsertTime;
	QDateTime m_CurInsertTime;

	bool m_bFirstFrame = true;
	TrainBasicInfo m_stLastTrainInfo;
	TrainBasicInfo m_stCurTrainInfo;						// �г���ǰ״̬
	E_TRAIN_UP_DOWN_TYPE m_eTrainUpDownType;			// �����з���
	QList<QPointF> m_lstTrainHistoryUp;		// �����г���ʷ״̬����
	QList<QPointF> m_lstTrainHistoryDown;		// �����г���ʷ״̬����

	int m_nChangeUpDowmTimes = 0;				// �������л�����
};


#ifndef TRAINENTITY
#define TRAINENTITY (*CTrainEntity::GetInstance())
#endif