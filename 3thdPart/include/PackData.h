#ifndef __STCLIENTPACKDATA_H__
#define __STCLIENTPACKDATA_H__
#include <string.h>
//�ͻ������ݷ��Ͱ�����
#ifndef safeDelete
#define safeDelete(p) {if((p)!=NULL){ delete (p);(p)=NULL; }}
#endif

#ifndef safeDeleteArr
#define safeDeleteArr(p) {if((p)!=NULL){ delete [](p);(p)=NULL; }}
#endif

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;

#define MAXPACK_LEN   4096 //ÿ�����ݰ���ֽ���Ŀ


#pragma pack(push,1)


//��ͷ����
typedef struct stPackHead
{
	byte head1;//��ͷ0xaa
	byte head2;//��ͷ0xff
	byte cmd;//��Ϣ���� 0x00 ��ͨ���� ;0xaf ������Ϣ; 0x01 ����Ϣ ;0x02 ������Ϣ ;0x03 ������Ϣ;0x04 ����id
	byte id;//���ݱ�ʶ0~0xFF
	char ip[16];//������ip
	uint idCode;//�ͻ���id v3����
	uint port;//�����߶˿�
	stPackHead()
	{
		head1 = 0xaa;
		head2 = 0xff;
		cmd = 0;
		id = 0;
		idCode = 0;
		memset(ip, 0, sizeof(ip));
	}
}PackHead;

//�ͻ��˷��͵����ݰ�
typedef struct stClientPackData
{
	stClientPackData()
	{
		dataSize = 0;
		data = NULL;
	}
	stClientPackData(byte id, const byte* buffer, uint size)
	{
		stClientPackData::stClientPackData();
		if (buffer == NULL || size == 0)
		{
			this->data = NULL;
			this->dataSize = size;
			return;
		}
		this->data = new byte[size];
		if (this->data != NULL)
		{
			memcpy(this->data, buffer, size);
			this->dataSize = size;
		}
	}
	stClientPackData(const stClientPackData &other)
	{
		*this = other;
	}
	stClientPackData& operator=(const stClientPackData &other)
	{
		if (this == &other)
		{
			return *this;
		}
		this->head = other.head;
		this->dataSize = other.dataSize;
		safeDeleteArr(this->data);
		if (other.data != NULL&& other.dataSize > 0)
		{
			this->data = new byte[other.dataSize];
			if (this->data != NULL)
			{
				memcpy(this->data, other.data, other.dataSize);
			}
		}
	}
	~stClientPackData()
	{
		safeDeleteArr(this->data);
	}
	stPackHead head;
	ushort dataSize;//���ݳ���
	byte* data;//���ݻ�����
}ClientPackData;


//������Ϣ
typedef struct stSubscibeData
{
	PackHead head;//����ͷ
	ushort count;//���ĵ����ݸ���
	byte dataIds[255];//��ඩ��255������
	stSubscibeData()
	{
		head.cmd = 0xaf;
		head.head1 = 0xaa;
		head.head2 = 0xff;
		head.id = 0;
		head.idCode = 0;
		memset(head.ip, 0, sizeof(head.ip));
		head.port = 0;
		count = 0;
		memset(dataIds, 0, 255);
	}
}SubscibeData;

enum EnClientState
{
	en_connected, //�����Ϸ�����ʱ��״̬
	en_disconnected,//���ӶϿ�ʱ״̬
	en_reconnecting //��������
};

//udp��������
typedef struct stBusHeartbeat
{
	PackHead head;//����ͷ
	ushort len;
	byte data[4];

	stBusHeartbeat()
	{
		len = 4;
	}
}BusHeartbeat;

//����ID����
typedef struct  stBusSetIdCode
{
	PackHead head;//����ͷ
	ushort len;
	uint idCode;
	stBusSetIdCode()
	{
		idCode = 0;
		len = sizeof(idCode);
		head.cmd = 0x04;
	}
}BusSetIdCode;


//udpͨ������
typedef struct stBusP2pData
{
	PackHead head;//����ͷ
	ushort len;
	uint idCode;

	stBusP2pData()
	{
		head.cmd = 0x01;
		len = sizeof(idCode);
	}
}BusP2pData;

typedef struct stBusControl
{
	PackHead head;//����ͷ
	ushort len;
	uint ctr[4];
	

	stBusControl()
	{
		head.cmd = 0x01;
		len = sizeof(uint)*4;
	}
}BusControl;


#pragma pack(pop)


#endif //__STCLIENTPACKDATA_H__