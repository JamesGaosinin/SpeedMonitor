#ifndef __COMMON_H_
#define __COMMON_H_
#include <QString>
#include "..\..\SpeedMonitor\include\CommonHeader.h"

struct StationInfo
{
	float m_fGLB;				// 停车线公里标
	QString m_strStationName;	// 站点名称
	E_TRAIN_UP_DOWN_TYPE m_eUpDownType;			// 上下行（0：下行，1：上行）
};

#endif // !__COMMONHEADER_H_
