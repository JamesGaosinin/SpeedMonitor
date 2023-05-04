#ifndef __CS_CIRCUIT_PROTOCOL__H__
#define __CS_CIRCUIT_PROTOCOL__H__


typedef unsigned char byte;


//长沙项目通信协议
#pragma  pack(push,1)


typedef struct stCsCirProtReq
{
	byte head1;//起始位 0x55
	byte head2;//起始位 0xaa
	byte pack_flag;//数据包标识 1 请求

    /*req_type
	1:请求设置元件值； 
	2 设置元件状态；
	3 设置元件导通故障；
	4 设置元件状态故障；
	5 取消元件导通故障； 
	6 取消元件状态故障；
	7 清除故障； 
	8 获取元件值；
	9 获取元件状态
	10 设置窗口显示隐藏
	*/
	byte req_type;//请求类型 

	char cir_name[50];//元件名称
	byte req_val;//填写附加数据如 设置元件值 状态故障时的状态值，req_type为10时，req_val=1显示窗口，req_val=0隐藏窗口
	
	byte end;//0xab//包尾
	stCsCirProtReq()
	{
		memset(this, 0, sizeof(*this));
	}
}CsCirProtReq;



typedef struct stCsCirProtRes
{
	byte head1;//起始位 0x55
	byte head2;//起始位 0xaa
	byte pack_flag;//数据包标识 0回复

	/*res_type
	1:设置元件值回复；
	2 设置元件状态回复；
	3 设置元件导通故障回复；
	4 设置元件状态故障回复；
	5 取消元件导通故障回复；
	6 取消元件状态故障回复；
	7 清除故障回复；
	8 获取元件值回复；
	9 获取元件状态回复*/

	byte res_type;//回复类型

	char cir_name[50];//元件名称
	byte res_val;//回复数据，如元件状态，元件值
	
	byte end;//0xab//包尾
	stCsCirProtRes()
	{
		memset(this, 0, sizeof(*this));
	}
}CsCirProtRes;





#pragma pack(pop)

#endif //__CS_CIRCUIT_PROTOCOL__H__