#ifndef  _CMFILETRANSFER_H_
#define _CMFILETRANSFER_H_


#ifdef MFILETRANSFER_EXPORTS
#define MFILETRANSFER_API __declspec(dllexport)
#else
#define MFILETRANSFER_API __declspec(dllimport)
#pragma comment(lib,"MFileTransfer.lib")
#endif

// 此类是从 MFileTransfer.dll 导出的
#pragma  pack(push,1)

//发送文件时可选的文件附带参数
struct FileArgment2
{
	unsigned char cmd;//附带命令（1：作业考核，2：故障考试， 4：故障文件同传5：流程处理文件同传）
	unsigned char* data;//附带数据指针
	unsigned short data_size;//附带数据长度，不能超过400字节

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
// Qualifier:文件接收回调函数
// Parameter: const char* filePath 文件路径
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
	// Qualifier:初始化函数
	// Parameter: const char * pClient
	//************************************
	void Init(const char* pClient = "fileTransfer");

	//************************************
	// Method:    SendFile
	// FullName:  CMFileTransfer::SendFile
	// Access:    public 
	// Returns:   bool
	// Qualifier:以默认消息id发送文件
	// Parameter: const char * filePath
	// Parameter: FileArgment2 * pFileArg
	//************************************
	bool SendFile(const char* filePath, FileArgment2* pFileArg);

	//************************************
	// Method:    SendFileEx
	// FullName:  CMFileTransfer::SendFileEx
	// Access:    public 
	// Returns:   bool
	// Qualifier:以自定义消息ID发送文件
	// Parameter: const char * filePath 文件路径
	// Parameter: byte msg_id busclient 消息id
	// Parameter: FileArgment2 * pFileArg 文件附带参数
	//************************************
	bool SendFileEx(const char* filePath, byte msg_id, FileArgment2* pFileArg);

	
	//************************************
	// Method:    SetOnRecvFileFunc
	// FullName:  CMFileTransfer::SetOnRecvFileFunc
	// Access:    public 
	// Returns:   void
	// Qualifier:设置文件接收到时的回调函数
	// Parameter: FileRecvCallback func
	// Parameter: void * puser 用户传入的指针，将在文件接收回调函数传出
	//************************************
	void SetOnRecvFileFunc(FileRecvCallback func, void* puser);

	
	//************************************
	// Method:    SetSaveDir
	// FullName:  CMFileTransfer::SetSaveDir
	// Access:    public 
	// Returns:   void
	// Qualifier:设置文件保存目录，不设置的话默认目录为\Documents\FileTransfer
	// Parameter: const char * dirPath
	//************************************
	void SetSaveDir(const char* dirPath);

	//************************************
	// Method:    GetSaveDir
	// FullName:  CMFileTransfer::GetSaveDir
	// Access:    public 
	// Returns:   const char*
	// Qualifier:获取文件保存目录
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