#ifndef __COMMONHEADER_H_
#define __COMMONHEADER_H_
#include <QString>

#pragma pack(push, 1)

typedef unsigned char byte;

enum E_TRAIN_UP_DOWN_TYPE
{
	E_TRAIN_UP_DOWN_TYPE_DOWN = 0,		// 下行
	E_TRAIN_UP_DOWN_TYPE_UP=1,			// 上行
};

enum E_TRAIN_ORIENTATION_TYPE
{
	E_TRAIN_ORIENTATION_TYPE_BACK = 0,	// 后退
	E_TRAIN_ORIENTATION_TYPE_FRONT=1,		// 前进
};

/********************************************
*end 岳明结构体
*********************************************/

/*结构定义*/
//教师机接收数据ID：0x24
//教师机发出数据ID：0x23
//simulator_no "all"表示所有客户端
#define  SIMULATORNOLEN 20
#define  DEVICENAMELEN 30
enum class techer_net_type : byte
{
	en_techer_net_time,//教师机下发时间设置
	en_techer_net_reset,//教师机下发重启客户算程序
	en_techer_net_online,//在线状态消息
	en_techer_net_self_check,//自检消息
	en_techer_net_log,//日志消息
	en_techer_net_shutdown,//关机 重启
	en_techer_net_circuit_ctrl,//电路图控制
	en_techer_net_create_metro,//教师机设置场景位置
	en_techer_net_operator_rec,//操作记录消息

	en_techer_clear_fault,//清除故障

	DC_LognLineCmd,		//在线包
	DC_EndEaxm,//结束考试
	DC_BeginEaxm,//开始考试

	en_techer_reset_switch, //重置开关

	DC_EndWork,//结束作业
	DC_BeginWork,//开始作业
};

struct techer_head
{
	techer_net_type net_type;//数据类型
	char simulator_no[SIMULATORNOLEN];//模拟器编号
};

typedef struct _tagTimeSyncMsg : public techer_head
{
	byte request_mode;	//请求方式 0--教师机主动发送，1--子系统请求
	//SYSTEMTIME sys_time;
	int year;
	int month;
	int day;

	int h;
	int m;
	int s;
}NET_TIMESYNC_MSG;

struct TrainBasicInfo
{
	QString m_strDevicdNum;		// 设备号
	QString m_strTranSerialNum;	// 列车号
	QString m_strRailName;		// 轨道名
	int m_nUpOrDown;			// 上下行
	int m_nDirection;			// 前进后退
	float m_fSpeed;				// 速度
	float m_fRelativePosition;	// 偏移位置
	float m_fAbsolutePosition;	// 公里标位置

	long long m_lCurTime;		// 当前时间

	TrainBasicInfo()
	{
		m_nUpOrDown = 1;
		m_nDirection = 1;
		m_fSpeed = 0.0f;
		m_fRelativePosition = 0.0f;
		m_fAbsolutePosition = 0.0f;
	}
};

#pragma pack(pop)

#endif