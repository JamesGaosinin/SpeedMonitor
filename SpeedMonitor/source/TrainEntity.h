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
	TrainBasicInfo m_stCurTrainInfo;						// 列车当前状态
	E_TRAIN_UP_DOWN_TYPE m_eTrainUpDownType;			// 上下行放下
	QList<QPointF> m_lstTrainHistoryUp;		// 保存列车历史状态上行
	QList<QPointF> m_lstTrainHistoryDown;		// 保存列车历史状态下行

	int m_nChangeUpDowmTimes = 0;				// 上下行切换次数
};


#ifndef TRAINENTITY
#define TRAINENTITY (*CTrainEntity::GetInstance())
#endif