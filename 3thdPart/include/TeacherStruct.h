#ifndef __TEACHERSTRUCT_H__
#define __TEACHERSTRUCT_H__
#include <string>

typedef unsigned char byte;
#pragma pack(push,1)


/********************************************
*begin 岳明结构体
*********************************************/
#define LEN_USER_NAME	11
#define LEN_USER_ID		11
#define LEN_USER_PWD	11
#define LEN_USER_DATE	11
#define LEN_USER_GENDER	3

enum E_Login_Status
{
	E_Login_Status_Null=0,		// 未知
	E_Login_Status_Login,		// 登录
	E_Login_Status_Loginout,	// 登出
};

enum class USER_TYPE
{
	UT_NULL = 0,
	UT_ADMIN = 1,	//管理员
	UT_TEACHAR,	//教员
	UT_STUDENT,	//学员
};

//学员信息
typedef struct _tagUserInformation
{
	USER_TYPE	nUserType;
	int		nProType;				//专业分类
	char		szUserId[LEN_USER_ID];		//用户id，学号或工号~
	char		szLoginName[LEN_USER_NAME];
	char		szPassword[LEN_USER_PWD];
	char		szCreateDate[LEN_USER_DATE];	//创建时间	
	bool		bIsOnline;				//是否在线
	//Added by Larphin 2016/12/05 适应学员动态分组需求，添加层级id和性别
	int		nLayerid;			            //层级id
	char		szGender[LEN_USER_GENDER];		//性别
	_tagUserInformation()
	{
		memset(this, 0, sizeof(_tagUserInformation));
	}

public:

	bool IsLengthValid(std::string &strMsg)
	{
		if (strlen(szUserId) > LEN_USER_ID || strlen(szUserId) < 1)
		{
			strMsg = ("用户id长度错误，长度设置为0-10位。");
			return false;
		}
		if (strlen(szLoginName) > LEN_USER_NAME || strlen(szLoginName) < 1)
		{
			strMsg = ("用户名称长度错误，长度设置为0-10位。");
			return false;
		}
		if (strlen(szPassword) > LEN_USER_PWD || strlen(szPassword) < 1)
		{
			strMsg = ("用户密码长度错误，长度设置为0-10位。");
			return false;
		}
		return true;
	}

}USER_INFORMATION, *PUSER_INFORMATION;
typedef USER_INFORMATION UserInfo;


typedef struct _tagCircuitMsg
{
	char szDeviceId[8];	//设备id--unique_name
	char szIp[16];//模拟器IP
	byte nCmd;//1-设置导通故障，2-设置状态故障，3-取消导通故障，4-取消状态故障，5、清除所有故障
	byte nState;//状态
}NET_CIRCUIT_MSG;

//电路图网络消息
typedef NET_CIRCUIT_MSG NetCircuitMsg;


/*******************20171113 new*********************/
//id：0x98
typedef struct _tagTimeSyncMsg
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

struct SaftyDoorFault
{
	char name[20];
	bool is_set;
	SaftyDoorFault()
	{
		memset(this, 0, sizeof(*this));
	}
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

enum class techer_net_type: byte
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

	en_techer_reset_switch //重置开关
};

struct techer_head
{
	techer_net_type net_type;//数据类型
	char simulator_no[SIMULATORNOLEN];//模拟器编号
};

//在线数据包
struct  device_online_msg :public techer_head
{
	byte is_req;//是否是请求 1 教师机发送请求； 0 客户端回复
	char device_name[DEVICENAMELEN];//设备名称
	byte tag;

	device_online_msg()
	{
		memset(this, 0, sizeof(*this));
		this->net_type = techer_net_type::en_techer_net_online;
	}

};

struct  device_self_check :public techer_head
{
	char device_name[DEVICENAMELEN];
	char check_item[DEVICENAMELEN];
	byte result;//自检结果 1 正常 0 异常
	char des[50];//自检结果描述

	device_self_check()
	{
		memset(this, 0, sizeof(*this));
		this->net_type = techer_net_type::en_techer_net_self_check;
	}
};

//清除故障
struct  teach_clear_fault :public techer_head
{
	teach_clear_fault()
	{
		strcpy_s(this->simulator_no, "all");
		this->net_type = techer_net_type::en_techer_clear_fault;
	}
};

//重置开关
struct  teach_reset_switch :public techer_head
{
	teach_reset_switch()
	{
		strcpy_s(this->simulator_no, "all");
		this->net_type = techer_net_type::en_techer_reset_switch;
	}
};

struct ExamFileInfo
{
	char studentLognId[128];//学员登录ID
	float fExamScore;//考试成绩
	int nPassLine;	// 及格分数
	int nExamTime;	// 考试时间
	char ExamType[128];//考试类型
	char ExamName[128];//考试名称

};
//故障处理文件信息参数
struct FaultProcFileArg
{
	char simulator_no[SIMULATORNOLEN];//模拟器编号 all 或者具体编号比如 B001
	int time_min;//考试事件分钟
	char fault_type[128];
	int nFileOrder;//文件编号
	FaultProcFileArg()
	{
		memset(this, 0, sizeof(*this));
	}
};

//关机
struct teach_shutdown :public techer_head
{
	teach_shutdown()
	{
		strcpy_s(this->simulator_no, "all");
		this->net_type = techer_net_type::en_techer_net_shutdown;
	}
};



typedef struct stLognLine_Msg :public techer_head
{
	char LognIdName[32];
	E_Login_Status e_LotinStatus;// 登录状态
	stLognLine_Msg()
	{
		net_type = techer_net_type::DC_LognLineCmd;
		e_LotinStatus = E_Login_Status_Loginout;
	}
}LognLine_Msg;


typedef struct stendExam_Msg :public techer_head
{
	char LognIdName[32];
	int nLognState;//0结束考试
	stendExam_Msg()
	{
		net_type = techer_net_type::DC_EndEaxm;
	}
}endExam_Msg;

typedef struct stBeginExam_Msg :public techer_head
{
	char testPageName[128];//试卷名称
	char ExamCueMsg[128];//提示信息
	int nExamTime;//考试时间
	char recordName[128]; //记录名
	char typeName[128];		//类型名
	stBeginExam_Msg()
	{
		memset(this, 0, sizeof(*this));
		net_type = techer_net_type::DC_BeginEaxm;
	}

	stBeginExam_Msg(const char* pSimulator, const char* record, const char* pName, const char* pType, const char* pTip, const int& time)
	{
		memset(this, 0, sizeof(*this));
		net_type = techer_net_type::DC_BeginEaxm;
		strcpy_s(recordName, record);
		strcpy_s(simulator_no, pSimulator);
		strcpy_s(testPageName, pName);
		strcpy_s(typeName, pType);
		strcpy_s(ExamCueMsg, pTip);
		nExamTime = time;
	}
}BeginExam_Msg;

typedef struct stLoginAllow_Msg :public techer_head
{
	byte bAllowFlag;
	stLoginAllow_Msg()
	{
		bAllowFlag = false;

	}
}LoginAllow_Msg;



/*end南京项目结构定义*/

#pragma pack(pop)


#endif //__STCLIENTPACKDATA_H__