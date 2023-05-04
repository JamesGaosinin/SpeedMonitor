#ifndef  _CMFILETRANSFER_H_
#define _CMFILETRANSFER_H_


#ifdef MFILETRANSFER_EXPORTS
#define MFILETRANSFER_API __declspec(dllexport)
#else
#define MFILETRANSFER_API __declspec(dllimport)
#pragma comment(lib,"MFileTransfer.lib")
#endif

// �����Ǵ� MFileTransfer.dll ������
#pragma  pack(push,1)

//�����ļ�ʱ��ѡ���ļ���������
struct FileArgment2
{
	unsigned char cmd;//�������1����ҵ���ˣ�2�����Ͽ��ԣ� 4�������ļ�ͬ��5�����̴����ļ�ͬ����
	unsigned char* data;//��������ָ��
	unsigned short data_size;//�������ݳ��ȣ����ܳ���400�ֽ�

	FileArgment2()
	{
		this->cmd = 0;
		this->data = nullptr;
		this->data_size = 0;
	}
};
#pragma  pack(pop)

typedef unsigned char byte;

class  FileTransfer;
//************************************
// Method:    FileRecvCallback
// Access:    public 
// Returns:   void
// Qualifier:�ļ����ջص�����
// Parameter: const char* filePath �ļ�·��
// Parameter: void* arg 
// Parameter:bool &bdel
// Parameter: FileArgment2 * pFileArg
//************************************
typedef void(*FileRecvCallback) (const char* filePath,void* puser, bool &bdel, FileArgment2 &file_arg);

class MFILETRANSFER_API CMFileTransfer 
{
public:
	CMFileTransfer(void);
	virtual ~CMFileTransfer();

	
	//************************************
	// Method:    Init
	// FullName:  CMFileTransfer::Init
	// Access:    public 
	// Returns:   void
	// Qualifier:��ʼ������
	// Parameter: const char * pClient
	//************************************
	void Init(const char* pClient = "fileTransfer");

	//************************************
	// Method:    SendFile
	// FullName:  CMFileTransfer::SendFile
	// Access:    public 
	// Returns:   bool
	// Qualifier:��Ĭ����Ϣid�����ļ�
	// Parameter: const char * filePath
	// Parameter: FileArgment2 * pFileArg
	//************************************
	bool SendFile(const char* filePath, FileArgment2* pFileArg);

	//************************************
	// Method:    SendFileEx
	// FullName:  CMFileTransfer::SendFileEx
	// Access:    public 
	// Returns:   bool
	// Qualifier:���Զ�����ϢID�����ļ�
	// Parameter: const char * filePath �ļ�·��
	// Parameter: byte msg_id busclient ��Ϣid
	// Parameter: FileArgment2 * pFileArg �ļ���������
	//************************************
	bool SendFileEx(const char* filePath, byte msg_id, FileArgment2* pFileArg);

	
	//************************************
	// Method:    SetOnRecvFileFunc
	// FullName:  CMFileTransfer::SetOnRecvFileFunc
	// Access:    public 
	// Returns:   void
	// Qualifier:�����ļ����յ�ʱ�Ļص�����
	// Parameter: FileRecvCallback func
	// Parameter: void * puser �û������ָ�룬�����ļ����ջص���������
	//************************************
	void SetOnRecvFileFunc(FileRecvCallback func, void* puser);

	
	//************************************
	// Method:    SetSaveDir
	// FullName:  CMFileTransfer::SetSaveDir
	// Access:    public 
	// Returns:   void
	// Qualifier:�����ļ�����Ŀ¼�������õĻ�Ĭ��Ŀ¼Ϊ\Documents\FileTransfer
	// Parameter: const char * dirPath
	//************************************
	void SetSaveDir(const char* dirPath);

	//************************************
	// Method:    GetSaveDir
	// FullName:  CMFileTransfer::GetSaveDir
	// Access:    public 
	// Returns:   const char*
	// Qualifier:��ȡ�ļ�����Ŀ¼
	//************************************
	const char* GetSaveDir();
private:
	FileTransfer* m_impl;
	FileRecvCallback m_file_cb;
	void* m_arg;
};





#ifdef __cplusplus
extern "C" {
#endif

	MFILETRANSFER_API void* CreateCMFileTransfer();
	MFILETRANSFER_API void DeleteCMFileTransfer(void* handle);
	MFILETRANSFER_API void Init(void* handle, const char* pClient);
	MFILETRANSFER_API bool SendFile(void* handle, const char* filePath, FileArgment2* pFileArg);
	MFILETRANSFER_API bool SendFileEx(void* handle, const char* filePath, byte msg_id, FileArgment2* pFileArg);
	MFILETRANSFER_API void SetOnRecvFileFunc(void* handle, FileRecvCallback func, void* arg);
	MFILETRANSFER_API void SetSaveDir(void* handle, const char* dirPath);
	MFILETRANSFER_API const char* GetSaveDir(void* handle);

#ifdef __cplusplus
}
#endif
#endif //__IBUSCLIENT__H__