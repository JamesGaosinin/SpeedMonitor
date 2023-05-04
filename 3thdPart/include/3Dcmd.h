#ifndef __3DCMD_H__
#define __3DCMD_H__
#pragma pack(push,1)

typedef unsigned char  byte;





namespace _3Dcmd
{

	enum NetType :int
	{
		DT_Null = 0,
		DT_CreateTran,//��������1
		DT_RemoveTran,//�Ƴ�����2
		DT_SetTran,//���ó�����Ϣ3
		DT_SetTranSpeed,//���ó����ٶ�4
		DT_SetTranStatus,//���ó���״̬5
		DT_SetTranDir,//���ó�������6
		DT_SetTranDes,//���ó�������7
		DT_LocalCamera,//������������ͷ8
		DT_SetXHJ,//�����źŻ�9
		DT_SetSwitch,//���õ���10
		DT_CleanSwitch,//�������11
		DT_SetWeather,//��������12
		DT_SetTrouble,//���ù���13
		DT_SetTranLight,//���س���14
		RT_CMDResult,//��������15
		RT_TranInfo,//����������Ϣ16
		RT_YDQ,//��������Ӧ����17
		RT_XHJ,//�����źŻ�״̬18
		RT_Switch,//��������19
		DQ_Device,//��ѯ����20
		DM_Close,//�ر�ʵ��21
		DT_SetAllStatus,//�������г�״̬22
		DT_OpenThirdCamera,//��������������23
		DT_RoamStation,//������������24
		DT_ONLINE,//����25
		DT_OpenTWnd,//�Ա괰��26
		DT_GLB,//�����27
		RT_SwitchCheck,//������ 28
		DT_SetDistance,//���þ��� 29
		RT_Hang,//��������30
		DT_CleanTran,//�������31
		DT_Help,//��Ԯ32
		DT_HelpProcess,//��Ԯ��������33
		DT_UIControl,//���水ť��Ӧ34
		DT_XiChe, //ϴ����ҵ35
		DT_Notify, //��ʾ֪ͨ36
		DT_Wiper,//�����37
		DT_Door, //���س��� 38
		DT_BoradInPassenger, //�Ͽ� 39
		DT_BoradOutPassenger,//�¿� 40
		DT_ClearPassenger, //���41
		DT_FlushArrive,    // ˢ�µִ�λ��42
		DT_SetCourse,//�γ����� 43
		DT_StationPBM,//վ̨pbm 44
		DT_SetAllXHJ,//���������źŻ�45
		DT_BindTrainNumber,//�󶨳��κ� 46
		DT_CountDown,//����ʱ47
		DT_OperateRoom,//�������48
		DT_PassengerFlow = 49,	//     ���� 49
		DT_QiDi = 50, //     ���� 50
		DT_ChangeMonitor = 51,// ת������� 51
		DT_SetTrainFault = 52,//���û�������
		/// <summary>
		/// ��س��� 53
		/// </summary>
		DT_MonitorTrain = 53,
		/// <summary>
		/// ����̨�豸 54
		/// </summary>
		DT_OperateCaoZuoTaiDevice = 54,
		/// <summary>
		/// ����ָ̨�� 55
		/// </summary>
		DT_CaozuotaiPointer = 55,
		/// <summary>
		/// ����̨ͼƬ 56
		/// </summary>
		DT_CaozuotaiPic = 56,

		/// <summary>
		/// ����̨��ť��ɫ 57
		/// </summary>
		DT_CaozuotaiButtonColor = 57,

		/*2020-4-2*/
		DT_CorrectionTrain = 62,//������λ��
		/*2020-4-2*/


		DT_UIText = 74,//UI��ʾ��ǰ��ֹͣλ��=88

		DT_VehicleCollision=88,//��ײ��Ϣ

		DT_Exam = 105,//������Ϣ2021 12 13 wmj add
	};

enum WeatherOptions :int
{
	Clear = 0,//����
	Cloudy,//���� 1
	LightRain,//С�� 2
	Overcast,//����3      
	Snow,//Сѩ4
	Haze,//����5
	Fog,//��6
	Dawn,//����7
	Morning,//�糿8
	Afternoon,//����9
	Dusk,//�ƻ�10
	Night,//ҹ��11
	Sandstorm,//ɳ����12
	Thunderstorm,//�ױ�13
	SuiDao
};

enum SingleType
{
	Black = 0,
	Red,
	Yellow,
	Green,
	White,
	Blue
};



///����ͷ
typedef struct stCMD
{
	NetType nType;
}TCMD;


//2021-12-7
//typedef struct stCsCirProtReq
//{
//	byte head1;//��ʼλ 0x55
//	byte head2;//��ʼλ 0xaa
//	byte pack_flag;//���ݰ���ʶ 1 ����
//
//	/*req_type
//	1:��������Ԫ��ֵ��
//	2 ����Ԫ��״̬��
//	3 ����Ԫ����ͨ���ϣ�
//	4 ����Ԫ��״̬���ϣ�
//	5 ȡ��Ԫ����ͨ���ϣ�
//	6 ȡ��Ԫ��״̬���ϣ�
//	7 ������ϣ�
//	8 ��ȡԪ��ֵ��
//	9 ��ȡԪ��״̬
//	10 ���ô�����ʾ����
//	*/
//	byte req_type;//�������� 
//
//	char cir_name[50];//Ԫ������
//	byte req_val;//��д���������� ����Ԫ��ֵ ״̬����ʱ��״ֵ̬��req_typeΪ10ʱ��req_val=1��ʾ���ڣ�req_val=0���ش���
//
//	byte end;//0xab//��β
//	stCsCirProtReq()
//	{
//		memset(this, 0, sizeof(*this));
//	}
//}CsCirProtReq;

//2021-12-7

enum TranStatus
{
	TranStop = 0,//��ײ��һ�������ATS 
	TranRun,//�������跢��1
	TranBroken
};
/*2020-4-20*///����ײ
typedef struct stTrainRunInto :TCMD
{
	TranStatus m_TrainState;
	char TrainOrder1[16];//�����
	char TrainOrder2[16];//�����

}TrainRunInto;
/// <summary>
/// ͼƬ����
/// </summary>
//[StructLayout(LayoutKind.Sequential, Pack = 1)]
struct CaoZuoTaiPicture
{
	CaoZuoTaiPicture(const char* devicenm, int index, int sz, byte* buffer)
	{
		nType = NetType::DT_CaozuotaiPic;
		strcpy_s(devicename, devicenm);
		packindex = index;
		datasize = sz;
		memcpy(data, buffer, sz);
		//data = new byte[512];
		//Array.Copy(buffer, data, buffer.Length);
	}
	//[MarshalAsAttribute(UnmanagedType.I4)]
	NetType nType;
	//[MarshalAsAttribute(UnmanagedType.ByValTStr, SizeConst = 32)]
	char devicename[32];
	int packindex;
	int datasize;
	//[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 512)]
	byte data[512];
};
/// <summary>
/// ��������
/// </summary>
/// <param name="nType">����ͷ DT_CreateTran</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// <param name="strTranNum">���κ�</param>
/// <param name="strCurPath">��ʼ���</param>
/// <param name="dir">ǰ�����˱�ʶ 1ǰ��0����</param>
/// <param name="des">�����б�ʶ 1���У�0����</param>
/// <param name="speed">��ʼ�ٶ�</param>
/// <param name="tf">�����ڹ����ʼλ��</param>
typedef struct stCreateTran :TCMD
{
	char trainSernubmer[16];
	char strTranNum[16];
	char strCurPath[16];
	int dir;
	int des;
	float speed;
	float tf;
}TCreateTran;



/*2020-4-2*/
/// <summary>
/// ��Ԯ����
/// </summary>
/// <param name="nType">����ͷ DT_HelpProcess</param>
/// <param name="process">�������</param>
/// <param name="trainSernumber">������ţ��豸�ţ�</param>
/// <param name="process">��Ԯѡ��</param>
/// ׼��0
/// ����1
/// ����2 15m��
/// �ҿ�3 2m��
/// �ҽ�4 0m �ζ�
/// ����5
//[StructLayout(LayoutKind.Sequential, Pack = 1)]
//public struct HelpProcess
//{
//	public HelpProcess(string sernumber, int ip, bool helpCamera)
//	{
//		nType = OpNetWorkDataType.DT_HelpProcess;
//		trainSernumber = sernumber;
//		process = ip;
//		HelpCamera = helpCamera;
//	}
//	[MarshalAsAttribute(UnmanagedType.I4)]
//	public OpNetWorkDataType nType;
//	[MarshalAsAttribute(UnmanagedType.ByValTStr, SizeConst = 16)]
//	public string trainSernumber;
//	public int process;
//	public bool HelpCamera;
/// <summary>
/// ��������λ��
/// </summary>
typedef struct stHelpTrain :TCMD
{
	char trainSernubmer[16];//�������
	int nProcess;
	bool bHelpCamera;//��� �ٹر�


}HelpTrain;

typedef struct stCorrectionTrain :TCMD
{
	char trainSernubmer[16];//�������
	char trainRoadName[16];//���������
	float fKio;
	int nTrainDir;//������1����2����
	float f_TrainSpeed;
	

}CorrectionTrain;

/// <summary>
/// �Ƴ����� 
/// <param name="nType">����ͷ DT_RemoveTran</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// </summary>
typedef struct stNetRemoveTran :TCMD
{
	char trainSernubmer[16];
}TNetRemoveTran;

/// <summary>
/// ���ó�������
/// <param name="nType">����ͷ DT_SetTran</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// <param name="strCurPath">�������ڹ������</param>
/// <param name="ts">�г�״̬</param>
/// <param name="dir">�г����� 1ǰ����0����</param>
/// <param name="des">�����б�ʶ1���У�0����</param>
/// <param name="speed">�г��ٶ�</param>
/// <param name="tf">�г����ڹ�����λ��</param>
/// </summary>
typedef struct stNetSetTran :TCMD
{
	char trainSernubmer[16];
	char strCurPath[16];
	int ts;
	int dir;
	int des;
	float speed;
	float tf;
}TNetSetTran;


/*2019-11-7*/
typedef struct stTUITEXT :TCMD
{
	char trainSernubmer[16];
	float stopDistance;//ͣ������
	int dir;//������ 0�� 1��

}TUITEXT;

/*2019-11-7*/
/// <summary>
/// ���ó���״̬
/// <param name="nType">����ͷ DT_SetTranStatus</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// <param name="ts">״̬</param>
/// </summary>
typedef struct stSetTranStatus :TCMD
{
	char trainSernubmer[16];
	int ts;
}TSetTranStatus;

/// <summary>
/// ���ó��ٶ�
/// <param name="nType">����ͷ DT_SetTranSpeed</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// <param name="speed">�г��ٶ�</param>
/// </summary>
typedef struct stSetTranSpeed :TCMD
{
	char trainSernubmer[16];
	float speed;
}TSetTranSpeed;

/// <summary>
/// ���ó����з���
/// <param name="nType">����ͷ DT_SetTranDir</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// <param name="dir">��ʻ���� 1ǰ����0����</param>
/// </summary>
typedef struct stSetTranDir :TCMD
{
	char trainSernubmer[16];
	int dir;
}TSetTranDir;

/// <summary>
/// ���ó���Ŀ�귽��
/// <param name="nType">����ͷ DT_SetTranDes</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// <param name="des">�����з��� 1���У�0����</param>
/// </summary>
typedef struct stSetTranDes :TCMD
{
	char trainSernubmer[16];
	int des;
}TSetTranDes;


/// <summary>
/// ���������
/// <param name="nType">����ͷ DT_LocalCamera</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// <param name="beLocalBefore">��ͷλ�� 1,ǰ�˾�ͷ��0�󷽾�ͷ</param>
/// </summary>
typedef struct stLocalCamera :TCMD
{
	char trainSernubmer[16];
	int beLocalBefore;
}TLocalCamera;


/// <summary>
/// �����źŻ�
/// <param name="nType">����ͷ DT_SetTranDes</param>
/// <param name="strXHJ">�źŻ�</param>
/// <param name="uClr">0λ��</param>
/// <param name="cClr">1��λ</param>
/// <param name="dClr">2��λ</param>
/// ��ɫֵ Black =0 Red =1  Yellow= 2 Green=3 White=4 Blue =5;
/// </summary>
typedef struct stSetXHJ :TCMD
{
	char TrainPhNumber[16];
	char strXHJ[16];
	int uClr;
	int cClr;
	int dClr;
}TSetXHJ;


/// <summary>
/// ����ת�޻�
/// <param name="nType">����ͷ DT_SetSwitch</param>
/// <param name="strSwitch">��������</param>
/// <param name="switchStatus">����״̬</param>
///����λ(�м�λ)= 0;
///��λ =1;
///��λ =2 ;
/// </summary>   
typedef struct stSetSwitch :TCMD
{
	char TrainPhNumber[16];
	char strSwitch[16];
	int switchStatus;
}TSetSwitch;

/// <summary>
/// ��λת�޻�
/// <param name="nType">����ͷ DT_CleanSwitch</param>
/// <param name="iClean">���״̬ 0��λ��1��λ</param>
/// </summary>y>
typedef struct stCleanSwitch :TCMD
{
	int iclean;
}TCleanSwitch;


/// <summary>
/// ��������
/// <param name="nType">����ͷ DT_SetWeather</param>
/// <param name="weather">����ѡ��״̬</param>
/// Clear = 0,//����
///Cloudy,//���� 1
///LightRain,//С�� 2
///Overcast,//����3      
///Snow,//Сѩ4
///Haze,//����5
///Fog,//��6
///Dawn,//����7
///Morning,//�糿8
///Afternoon,//����9
///Dusk,//�ƻ�10
///Night,//ҹ��11
///Sandstorm,//ɳ����12
///Thunderstorm,//�ױ�13
///SuiDao
/// </summary>
typedef struct stSetWeather :TCMD
{
	int weather;
}TSetWeather;

/// <summary>
///  ���ù���
/// <param name="nType">����ͷ DT_SetTrouble</param>
/// <param name="trouble">��������</param>
/// <param name="nID">����ID</param> 
/// <param name="bs">���Ͽ���</param>
/// <param name="tf">���λ��</param>
/// <param name="strPath">�����</param>
/// </summary>
typedef struct stSetTrouble :TCMD
{
	int trouble;
	int nID;
	int bs;
	float tf;
	char strPath[16];
}TSetTrouble;

/// <summary>
/// ���ó���
/// <param name="nType">����ͷ DT_SetTranLight</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// <param name="lightType">������ 1С��2��</param>
/// <param name="lightValue">ֵ 1��0</param>
/// </summary>

typedef struct stSetTranLight :TCMD
{
	char trainSernubmer[16];
	int lightType;
	int lightValue;
}TSetTranLight;


/// <summary>
/// �����
/// <param name="nType">����ͷ RT_CMDResult</param>
/// <param name="nTypeCmdBack">��Ӧ����(Ψһ��ʶ)</param>
/// <param name="backValue">�����ʶ true �ɹ�,false  ʧ��</param>
/// <param name="strRSInfor">������Ϣ</param>
/// </summary>
typedef struct stCMDResult :TCMD
{
	char strTranPhNumber[16];
	NetType nTypeCmdBack;
	int backValue; //1 ����2 ɾ���� 3������ 4����  
	char strRSInfor[16];
	byte DoorState[10];//0-7�м� ��������ǳ�ͷ
	int nDoorDir;//1��2��
}TCMDResult;

/// <summary>
/// Ӧ��������
/// <param name="nType">����ͷ RT_YDQ</param>
/// <param name="strYDQ">Ӧ��������(Ψһ��ʶ)</param>
/// <param name="trainSernubmer">����Ӧ����������</param>
/// <summary>
typedef struct stRTYDQ :TCMD
{
	char strYDQ[16];
	char trainSernubmer[16];
}TRTYDQ;

/// <summary>
/// ������Ϣ����
/// <param name="nType">����ͷ RT_TranInfo</param>
/// <param name="strTranSernumber">������ţ��豸�ţ�</param>
/// <param name="strTranNumber">���κ�(Ψһ��ʶ)</param>
/// <param name="strPath">��ʼ���λ��</param>
/// <param name="dir">��ʼ�г�����</param>
/// <param name="speed">��ʼ�г��ٶ�</param>
/// <param name="tf">��ǰ���λ��0��1</param>
/// <param name="ts">����״̬</param>
/// <summary>
typedef struct stRTTranInfo :TCMD
{
	char strTranSernumber[16];
	char strTranNumber[16];
	char strPath[16];
	int dir;
	float speed;
	float tf;//��ǰ����� ͷѹ������� 
	int ts;
}RTTranInfo;

/// <summary>
/// ���������
/// <param name="nType">����ͷ DT_GLB</param>
/// <param name="strTranNum">������ţ��豸�ţ�</param>
/// <param name="strCurPath">��·</param>
/// <param name="dir">��ʻ����1ǰ����0����</param>
/// <param name="des">������ 1���У�0����</param>
/// <param name="speed">��ʻ�ٶ�</param>
/// <param name="tf">��·λ��</param>
/// <param name="ts">����״̬</param>
/// <param name="region">����</param>
/// </summary>
typedef struct stRTGLBInfo :TCMD
{
	char strTranNum[16];
	char strCurPath[16];

	char sCarriage1[16];
	char sCarriage2[16];
	char sCarriage3[16];
	char sCarriage4[16];
	char sCarriage5[16];
	char sCarriage6[16];
	int dir;	
	int des;
	float speed;
	float tf;
	int ts;
	int region;
}RTGLBInfoInfo;

/// <summary>
/// �������г���״̬
/// <param name="nType">����ͷ DT_SetAllStatus</param>
/// <param name="ts">����״̬</param>
/// </summary>
typedef struct stSetAllST :TCMD
{
	int ts;
}TSetAllST;

/// <summary>
/// �رճ��� 
/// <param name="nType">����ͷ DM_Close</param>
/// <param name="timeDelay">��ʱֵ</param>
/// time ��ʱʱ��s
/// </summary>
typedef struct stCmdClose :TCMD
{
	int timeDelay;
}TCmdClose;


/// <summary>
/// ����������
/// <param name="nType">����ͷ RT_SwitchCheck</param>
/// <param name="trainSernubmer">������ţ��豸�ţ�</param>
/// <param name="strSwitchName">��������</param>
/// <summary>
typedef struct stRTSwCheck :TCMD
{
	char trainSernubmer[16];
	char strSwitchName[16];
}RTSwCheck;



/// <summary>
/// ���������
/// <param name="nType">����ͷ DT_Wiper</param>
/// <param name="open"> mopen=1 ��,0 ��</param>
/// </summary>
typedef struct stOpenWiper :TCMD
{
	int mopen;
}TOpenWiper;

/// <summary>
/// �γ�����
/// <param name="nType">����ͷ DT_SetCourse</param>         
/// <param name="courseSet">1��ʼ�γ̣�0�ص��ȴ�����</param>    
/// <param name="strContent">�������� unicode����</param>
/// </summary>
typedef struct stCourseSet :TCMD
{
	int courseSet;
	char strContent[128];
}TCourseSet;

/// <summary>
/// ���ſ���
/// <param name="nType">����ͷ DT_Door</param>      
/// <param name="doortype">�������� 0 �ң�1��</param>
/// <param name="open">����ѡ��1��0��</param>
/// </summary>
typedef struct stOpenDoor :TCMD
{
	int doortype;
	int mopen;
}OpenDoor;

/// </summary>
/// ���������źŻ�
/// <param name="nType">����ͷ DT_SetAllXHJ</param>   
/// <param name="uclr">1��</param>
/// <param name="cclr">2��</param>
/// <param name="dclr">3��</param>
/// ��ɫֵ Black =0 Red =1  Yellow= 2 Green=3 White=4 Blue =5;
/// </summary>
typedef struct stSetAllSignal :TCMD
{
	char TrainPhNumber[16];
	
	int uClr;
	int cClr;
	int dClr;
}SetAllSignal;

/// <summary>
/// �������
/// <param name="nType">����ͷ DT_OperateRoom</param>    
/// <param name="operate">���� 1,�������2,�����뿪</param>   
/// </summary>
typedef struct stOperateRoom :TCMD
{
	int operate;
}OperateRoom;

/// <summary>
/// ����
/// <param name="nType">����ͷ DT_QiDi</param>   
/// <param name="raise">1���� 0�ر�</param>    
/// </summary>
typedef struct stTrainQidi :TCMD
{
	int raise;
}TrainQidi;

/// <summary>
/// <param name="nType">����ͷ DT_ChangeMonitor</param> 
/// <param name="swState"> ת�������״̬ swState 1�������Ӿ���2����վ̨���������棨���滥�⣬�������Ӿ��رռ������������������رղ��Ӿ���</param> 
/// </summary>
typedef struct stChangMonitor :TCMD
{
	char TrainPhNumber[16];
	int swState;
	int n3DStationId;
}ChangMonitor;


/// <summary>
/// ����ʱ
/// <param name="nType">����ͷ DT_CountDown</param>   
/// <param name="timebase">ʱ�����</param>
/// <param name="timeCount">����</param>
/// <param name="timeOps">ѡ�� 0 ����,1����,2�۳�,-1ȡ��</param>
/// </summary>
typedef struct stCountDown :TCMD
{
	char TrainPhNumber[16];
	int timeCount;
	int timeBase;
	int timeOps;
	char TimeName[16];
}CountDown;

//������Ϣ��ʾ
typedef struct stExamInfo :TCMD
{
	char trainSernubmer[16];
	int bShow;//0�ر���ʾ 1����������ʾ
	char content[200];//���Ͻ���ʾ������ ���೵�Ź��Ͽ��� utf8����
	int minute;//����ʱ�� ��������120���ӣ����Ͻ� 3d��ʾһ������ʱ��01:29:55 ��ʾ����1Сʱ29����55�� 
	stExamInfo()
	{
		memset(this, 0, sizeof(*this));
		nType = DT_Exam;
	}
}ExamInfo;

}
#pragma pack(pop)
#endif	
