#ifndef __COMMON_H_
#define __COMMON_H_
#include <QString>
#include "..\..\SpeedMonitor\include\CommonHeader.h"

struct StationInfo
{
	float m_fGLB;				// ͣ���߹����
	QString m_strStationName;	// վ������
	E_TRAIN_UP_DOWN_TYPE m_eUpDownType;			// �����У�0�����У�1�����У�
};

#endif // !__COMMONHEADER_H_
