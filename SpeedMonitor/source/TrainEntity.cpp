#include "TrainEntity.h"
#include <QMutexLocker>
#define POINTDISTANCE	(1.0f)		// 接受间隔距离
#define TIMEINTERVAL	(800)		// 接受间隔时间

CTrainEntity::CTrainEntity()
{
}

CTrainEntity::~CTrainEntity()
{
}

void CTrainEntity::AddTrainInfo(const TrainBasicInfo& stInfo)
{
	QMutexLocker locker(&m_Mutex);
	if (m_bFirstFrame)
	{
		m_stLastTrainInfo = stInfo;
		m_stCurTrainInfo = stInfo;
		m_eTrainUpDownType = (E_TRAIN_UP_DOWN_TYPE)stInfo.m_nUpOrDown;
		m_LastInsertTime = QDateTime::currentDateTime();
		m_bFirstFrame = false;
	}

	m_CurInsertTime = QDateTime::currentDateTime();
	if (m_LastInsertTime.msecsTo(m_CurInsertTime) < TIMEINTERVAL)
	{
		return;
	}

	m_stCurTrainInfo = stInfo;
	if (abs(m_stLastTrainInfo.m_fAbsolutePosition - stInfo.m_fAbsolutePosition) < POINTDISTANCE)
	{
		return;
	}

	QPointF posf(stInfo.m_fAbsolutePosition, stInfo.m_fSpeed);
	E_TRAIN_UP_DOWN_TYPE eType = (E_TRAIN_UP_DOWN_TYPE)stInfo.m_nUpOrDown;
	if (eType == E_TRAIN_UP_DOWN_TYPE_UP)
	{
		m_lstTrainHistoryUp.push_back(posf);
		if (m_lstTrainHistoryUp.size() > 5000)
		{
			m_lstTrainHistoryUp.clear();
		}
	}
	else if (eType == E_TRAIN_UP_DOWN_TYPE_DOWN)
	{
		m_lstTrainHistoryDown.push_back(posf);
		if (m_lstTrainHistoryDown.size() > 5000)
		{
			m_lstTrainHistoryDown.clear();
		}
	}

	if (eType != m_eTrainUpDownType)
	{
		m_nChangeUpDowmTimes++;
		m_eTrainUpDownType = eType;
		if (m_nChangeUpDowmTimes > 1)
		{
			ClearHistoryInfo();
			m_nChangeUpDowmTimes = 0;
			m_bFirstFrame = false;
		}
	}

	m_LastInsertTime = m_CurInsertTime;
	m_stLastTrainInfo = m_stCurTrainInfo;
}

QList<QPointF> CTrainEntity::GetHistoryInfo(E_TRAIN_UP_DOWN_TYPE eType)
{
	QMutexLocker locker(&m_Mutex);
	if (eType == E_TRAIN_UP_DOWN_TYPE_UP)
	{
		return m_lstTrainHistoryUp;
	}
	else if (eType == E_TRAIN_UP_DOWN_TYPE_DOWN)
	{
		return m_lstTrainHistoryDown;
	}
	return QList<QPointF>();
}

TrainBasicInfo CTrainEntity::GetCurTrainInfo()
{
	QMutexLocker locker(&m_Mutex);
	return m_stCurTrainInfo;
}

E_TRAIN_UP_DOWN_TYPE CTrainEntity::GetCurUpDpwnType()
{
	QMutexLocker locker(&m_Mutex);
	return m_eTrainUpDownType;
}

void CTrainEntity::ClearHistoryInfo()
{
	m_lstTrainHistoryUp.clear();
	m_lstTrainHistoryDown.clear();
}
