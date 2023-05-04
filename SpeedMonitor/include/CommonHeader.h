#ifndef __COMMONHEADER_H_
#define __COMMONHEADER_H_
#include <QString>

#pragma pack(push, 1)

typedef unsigned char byte;

enum E_TRAIN_UP_DOWN_TYPE
{
	E_TRAIN_UP_DOWN_TYPE_DOWN = 0,		// ����
	E_TRAIN_UP_DOWN_TYPE_UP=1,			// ����
};

enum E_TRAIN_ORIENTATION_TYPE
{
	E_TRAIN_ORIENTATION_TYPE_BACK = 0,	// ����
	E_TRAIN_ORIENTATION_TYPE_FRONT=1,		// ǰ��
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
enum class techer_net_type : byte
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

	en_techer_reset_switch, //���ÿ���

	DC_EndWork,//������ҵ
	DC_BeginWork,//��ʼ��ҵ
};

struct techer_head
{
	techer_net_type net_type;//��������
	char simulator_no[SIMULATORNOLEN];//ģ�������
};

typedef struct _tagTimeSyncMsg : public techer_head
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

struct TrainBasicInfo
{
	QString m_strDevicdNum;		// �豸��
	QString m_strTranSerialNum;	// �г���
	QString m_strRailName;		// �����
	int m_nUpOrDown;			// ������
	int m_nDirection;			// ǰ������
	float m_fSpeed;				// �ٶ�
	float m_fRelativePosition;	// ƫ��λ��
	float m_fAbsolutePosition;	// �����λ��

	long long m_lCurTime;		// ��ǰʱ��

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