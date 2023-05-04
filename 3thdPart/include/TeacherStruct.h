#ifndef __TEACHERSTRUCT_H__
#define __TEACHERSTRUCT_H__
#include <string>

typedef unsigned char byte;
#pragma pack(push,1)


/********************************************
*begin �����ṹ��
*********************************************/
#define LEN_USER_NAME	11
#define LEN_USER_ID		11
#define LEN_USER_PWD	11
#define LEN_USER_DATE	11
#define LEN_USER_GENDER	3

enum E_Login_Status
{
	E_Login_Status_Null=0,		// δ֪
	E_Login_Status_Login,		// ��¼
	E_Login_Status_Loginout,	// �ǳ�
};

enum class USER_TYPE
{
	UT_NULL = 0,
	UT_ADMIN = 1,	//����Ա
	UT_TEACHAR,	//��Ա
	UT_STUDENT,	//ѧԱ
};

//ѧԱ��Ϣ
typedef struct _tagUserInformation
{
	USER_TYPE	nUserType;
	int		nProType;				//רҵ����
	char		szUserId[LEN_USER_ID];		//�û�id��ѧ�Ż򹤺�~
	char		szLoginName[LEN_USER_NAME];
	char		szPassword[LEN_USER_PWD];
	char		szCreateDate[LEN_USER_DATE];	//����ʱ��	
	bool		bIsOnline;				//�Ƿ�����
	//Added by Larphin 2016/12/05 ��ӦѧԱ��̬����������Ӳ㼶id���Ա�
	int		nLayerid;			            //�㼶id
	char		szGender[LEN_USER_GENDER];		//�Ա�
	_tagUserInformation()
	{
		memset(this, 0, sizeof(_tagUserInformation));
	}

public:

	bool IsLengthValid(std::string &strMsg)
	{
		if (strlen(szUserId) > LEN_USER_ID || strlen(szUserId) < 1)
		{
			strMsg = ("�û�id���ȴ��󣬳�������Ϊ0-10λ��");
			return false;
		}
		if (strlen(szLoginName) > LEN_USER_NAME || strlen(szLoginName) < 1)
		{
			strMsg = ("�û����Ƴ��ȴ��󣬳�������Ϊ0-10λ��");
			return false;
		}
		if (strlen(szPassword) > LEN_USER_PWD || strlen(szPassword) < 1)
		{
			strMsg = ("�û����볤�ȴ��󣬳�������Ϊ0-10λ��");
			return false;
		}
		return true;
	}

}USER_INFORMATION, *PUSER_INFORMATION;
typedef USER_INFORMATION UserInfo;


typedef struct _tagCircuitMsg
{
	char szDeviceId[8];	//�豸id--unique_name
	char szIp[16];//ģ����IP
	byte nCmd;//1-���õ�ͨ���ϣ�2-����״̬���ϣ�3-ȡ����ͨ���ϣ�4-ȡ��״̬���ϣ�5��������й���
	byte nState;//״̬
}NET_CIRCUIT_MSG;

//��·ͼ������Ϣ
typedef NET_CIRCUIT_MSG NetCircuitMsg;


/*******************20171113 new*********************/
//id��0x98
typedef struct _tagTimeSyncMsg
{
	byte request_mode;	//����ʽ 0--��ʦ���������ͣ�1--��ϵͳ����
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
*end �����ṹ��
*********************************************/

/*�ṹ����*/
//��ʦ����������ID��0x24
//��ʦ����������ID��0x23
//simulator_no "all"��ʾ���пͻ���
#define  SIMULATORNOLEN 20
#define  DEVICENAMELEN 30

enum class techer_net_type: byte
{
	en_techer_net_time,//��ʦ���·�ʱ������
	en_techer_net_reset,//��ʦ���·������ͻ������
	en_techer_net_online,//����״̬��Ϣ
	en_techer_net_self_check,//�Լ���Ϣ
	en_techer_net_log,//��־��Ϣ
	en_techer_net_shutdown,//�ػ� ����
	en_techer_net_circuit_ctrl,//��·ͼ����
	en_techer_net_create_metro,//��ʦ�����ó���λ��
	en_techer_net_operator_rec,//������¼��Ϣ

	en_techer_clear_fault,//�������

	DC_LognLineCmd,		//���߰�
	DC_EndEaxm,//��������
	DC_BeginEaxm,//��ʼ����

	en_techer_reset_switch //���ÿ���
};

struct techer_head
{
	techer_net_type net_type;//��������
	char simulator_no[SIMULATORNOLEN];//ģ�������
};

//�������ݰ�
struct  device_online_msg :public techer_head
{
	byte is_req;//�Ƿ������� 1 ��ʦ���������� 0 �ͻ��˻ظ�
	char device_name[DEVICENAMELEN];//�豸����
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
	byte result;//�Լ��� 1 ���� 0 �쳣
	char des[50];//�Լ�������

	device_self_check()
	{
		memset(this, 0, sizeof(*this));
		this->net_type = techer_net_type::en_techer_net_self_check;
	}
};

//�������
struct  teach_clear_fault :public techer_head
{
	teach_clear_fault()
	{
		strcpy_s(this->simulator_no, "all");
		this->net_type = techer_net_type::en_techer_clear_fault;
	}
};

//���ÿ���
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
	char studentLognId[128];//ѧԱ��¼ID
	float fExamScore;//���Գɼ�
	int nPassLine;	// �������
	int nExamTime;	// ����ʱ��
	char ExamType[128];//��������
	char ExamName[128];//��������

};
//���ϴ����ļ���Ϣ����
struct FaultProcFileArg
{
	char simulator_no[SIMULATORNOLEN];//ģ������� all ���߾����ű��� B001
	int time_min;//�����¼�����
	char fault_type[128];
	int nFileOrder;//�ļ����
	FaultProcFileArg()
	{
		memset(this, 0, sizeof(*this));
	}
};

//�ػ�
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
	E_Login_Status e_LotinStatus;// ��¼״̬
	stLognLine_Msg()
	{
		net_type = techer_net_type::DC_LognLineCmd;
		e_LotinStatus = E_Login_Status_Loginout;
	}
}LognLine_Msg;


typedef struct stendExam_Msg :public techer_head
{
	char LognIdName[32];
	int nLognState;//0��������
	stendExam_Msg()
	{
		net_type = techer_net_type::DC_EndEaxm;
	}
}endExam_Msg;

typedef struct stBeginExam_Msg :public techer_head
{
	char testPageName[128];//�Ծ�����
	char ExamCueMsg[128];//��ʾ��Ϣ
	int nExamTime;//����ʱ��
	char recordName[128]; //��¼��
	char typeName[128];		//������
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



/*end�Ͼ���Ŀ�ṹ����*/

#pragma pack(pop)


#endif //__STCLIENTPACKDATA_H__