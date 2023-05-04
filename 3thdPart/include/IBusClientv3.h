#ifndef __IBUSCLIENT__H__
#define __IBUSCLIENT__H__

#ifdef BUSCLIENTV3_EXPORTS
#define BUSCLIENT_API __declspec(dllexport)
#else
#define BUSCLIENT_API __declspec(dllimport)
#pragma comment(lib,"BusClientv3.lib")
#endif

#include "PackData.h"
class IBusClient;
/*enum EnClientState
{
	en_connected, //�����Ϸ�����ʱ��״̬
	en_disconnected,//���ӶϿ�ʱ״̬
	en_reconnecting //��������
};*/

//���ݴ�����ָ������
typedef void (*BusDataCallback) (ClientPackData* pData,void* arg);

//״̬�ı�ʱ����ָ�붨��
typedef void(*BusStateChangeCallback) (IBusClient* pClient,EnClientState state, void* arg);


class IBusClient
{
public:
	virtual ~IBusClient(){}
	//************************************
	// Method:    SetDataCallback
	// FullName:  IBusClient::SetDataCallback
	// Access:    virtual public 
	// Returns:   void
	// Qualifier: �������ݽ��յ��Ժ�Ļص�����
	// Parameter: BusDataCallback dataCb ����ָ��
	// Parameter: void* arg ���ûص�����ʱ������arg����
	//************************************
	virtual void SetDataCallback(BusDataCallback cb, void* arg) = 0;

	//************************************
	// Method:    SetStateChangeCallback
	// FullName:  IBusClient::SetStateChangeCallback
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:����client״̬�ı�ʱ�ص�����
	// Parameter: BusStateChangeCallback cb �ص�����ָ��
	// Parameter: void * arg ���ûص�����ʱ�ĸ��Ӳ���ָ��
	//************************************
	virtual void SetStateChangeCallback(BusStateChangeCallback cb, void* arg) = 0;

	//************************************
	// Method:    Start
	// FullName:  IBusClient::Start
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier: �����ͻ������ӣ��������������ܷ����������������
	//************************************
	virtual bool Start() = 0;

	//************************************
	// Method:    Stop
	// FullName:  IBusClient::Stop
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:����Stop��Ͽ������˵����ӣ������ٷ�������
	//************************************
	virtual bool Stop() = 0;

	//************************************
	// Method:    SendData
	// FullName:  IBusClient::SendData
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier: ���øýӿڷ�������
	// Parameter: byte id �������ݵ�ID
	// Parameter: const byte * data Ҫ���͵�����
	// Parameter: ushort size ���͵����ݳ���
	//************************************
	virtual bool SendData(byte id,const byte* data,ushort size) = 0;

	//************************************
	// Method:    GetClientId
	// FullName:  IBusClient::GetIdCode
	// Access:    virtual public 
	// Returns:   uint
	// Qualifier:��ȡ�ͻ���ID v3
	//************************************
	virtual uint GetIdCode() = 0;


	//************************************
	// Method:    GetSubscribeData
	// FullName:  IBusClient::GetSubscribeData
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:��ȡ���ĵ�����id
	// Parameter: byte subsData[255]
	// Parameter: int outCount
	//************************************
	virtual void GetSubscribeData(byte subIds[255], int *outCount) = 0;

	//************************************
	// Method:    SetSubscribeData
	// FullName:  IBusClient::SetSubscribeData
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:��̬���ö�������id
	// Parameter: byte * subsData
	// Parameter: int count
	//************************************
	virtual bool SetSubscribeData(byte* subIds,int inCount) = 0;
};
#ifdef __cplusplus
extern "C" {
#endif
	//************************************
	// Method:    CreateIBusClient
	// FullName:  CreateIBusClient
	// Access:    public 
	// Returns:   BUSCLIENT_API IBusClient*
	// Qualifier: ����һ���ͻ���
	// Parameter: const char * clientId �����ļ��еĿͻ�������ID
	// Parameter: char * err �������ʧ�ܣ����ش�����Ϣ
	//************************************
	BUSCLIENT_API IBusClient* CreateIBusClient(const char* clientId, char* err);

	//************************************
	// Method:    ReleaseIBusClient
	// FullName:  ReleaseIBusClient
	// Access:    public 
	// Returns:   BUSCLIENT_API void
	// Qualifier:�ͷ��Ѿ������Ŀͻ���
	// Parameter: IBusClient * pClient �Ѿ������Ŀͻ���ָ��
	//************************************
	BUSCLIENT_API void ReleaseIBusClient(IBusClient *pClient);


	/***********************************************************/
	/***********************************************************/
	/*************************����Ϊc�ӿ�************************/
	/***********************************************************/
	/***********************************************************/
	typedef  void* HBusClient;

	typedef void(*HBusStateChangeCallback) (HBusClient pClient, EnClientState state, void* arg);

	//************************************
	// Method:    CreateHBusClient
	// FullName:  CreateHBusClient
	// Access:    public 
	// Returns:   BUSCLIENT_API HBusClient
	// Qualifier:�����ͻ��˾��
	// Parameter: const char * clientId
	// Parameter: char * err
	//************************************
	BUSCLIENT_API HBusClient CreateHBusClient(const char* clientId, char* err);

	//************************************
	// Method:    ReleaseIBusClient
	// FullName:  ReleaseIBusClient
	// Access:    public 
	// Returns:   BUSCLIENT_API void
	// Qualifier:�ͷſͻ��˾��
	// Parameter: HBusClient hClient
	//************************************
	BUSCLIENT_API void ReleaseHBusClient(HBusClient hClient);

	//************************************
	// Method:    SetDataCallback
	// FullName:  IBusClient::SetDataCallback
	// Access:    virtual public 
	// Returns:   void
	// Qualifier: �������ݽ��յ��Ժ�Ļص�����
	// Parameter: BusDataCallback dataCb ����ָ��
	// Parameter: void* arg ���ûص�����ʱ������arg����
	//************************************
	BUSCLIENT_API void SetDataCallback(HBusClient hClient,BusDataCallback cb, void* arg);

	//************************************
	// Method:    SetStateChangeCallback
	// FullName:  IBusClient::SetStateChangeCallback
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:����client״̬�ı�ʱ�ص�����
	// Parameter: BusStateChangeCallback cb �ص�����ָ��
	// Parameter: void * arg ���ûص�����ʱ�ĸ��Ӳ���ָ��
	//************************************
	BUSCLIENT_API void SetStateChangeCallback(HBusClient hClient, HBusStateChangeCallback cb, void* arg);

	//************************************
	// Method:    Start
	// FullName:  IBusClient::Start
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier: �����ͻ������ӣ��������������ܷ����������������
	//************************************
	BUSCLIENT_API bool Start(HBusClient hClient);

	//************************************
	// Method:    Stop
	// FullName:  IBusClient::Stop
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:����Stop��Ͽ������˵����ӣ������ٷ�������
	//************************************
	BUSCLIENT_API bool Stop(HBusClient hClient);

	//************************************
	// Method:    SendData
	// FullName:  IBusClient::SendData
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier: ���øýӿڷ�������
	// Parameter: byte id �������ݵ�ID
	// Parameter: const byte * data Ҫ���͵�����
	// Parameter: ushort size ���͵����ݳ���
	//************************************
	BUSCLIENT_API bool SendData(HBusClient hClient, byte id, const byte* data, ushort size);


	//��ȡ�ͻ���ID v3
	BUSCLIENT_API uint GetIdCode(HBusClient hClient);


	//************************************
	// Method:    GetSubscribeData
	// FullName:  IBusClient::GetSubscribeData
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:��ȡ���ĵ�����id
	// Parameter: byte subsData[255]
	// Parameter: int outCount
	//************************************
	BUSCLIENT_API void GetSubscribeData(HBusClient hClient,byte subIds[255], int *outCount);

	//************************************
	// Method:    SetSubscribeData
	// FullName:  IBusClient::SetSubscribeData
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:��̬���ö�������id
	// Parameter: byte * subsData
	// Parameter: int count
	//************************************
	BUSCLIENT_API bool SetSubscribeData(HBusClient hClient,byte* subIds, int inCount);

#ifdef __cplusplus
}
#endif
#endif //__IBUSCLIENT__H__