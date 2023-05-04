#ifndef __CS_CIRCUIT_PROTOCOL__H__
#define __CS_CIRCUIT_PROTOCOL__H__


typedef unsigned char byte;


//��ɳ��Ŀͨ��Э��
#pragma  pack(push,1)


typedef struct stCsCirProtReq
{
	byte head1;//��ʼλ 0x55
	byte head2;//��ʼλ 0xaa
	byte pack_flag;//���ݰ���ʶ 1 ����

    /*req_type
	1:��������Ԫ��ֵ�� 
	2 ����Ԫ��״̬��
	3 ����Ԫ����ͨ���ϣ�
	4 ����Ԫ��״̬���ϣ�
	5 ȡ��Ԫ����ͨ���ϣ� 
	6 ȡ��Ԫ��״̬���ϣ�
	7 ������ϣ� 
	8 ��ȡԪ��ֵ��
	9 ��ȡԪ��״̬
	10 ���ô�����ʾ����
	*/
	byte req_type;//�������� 

	char cir_name[50];//Ԫ������
	byte req_val;//��д���������� ����Ԫ��ֵ ״̬����ʱ��״ֵ̬��req_typeΪ10ʱ��req_val=1��ʾ���ڣ�req_val=0���ش���
	
	byte end;//0xab//��β
	stCsCirProtReq()
	{
		memset(this, 0, sizeof(*this));
	}
}CsCirProtReq;



typedef struct stCsCirProtRes
{
	byte head1;//��ʼλ 0x55
	byte head2;//��ʼλ 0xaa
	byte pack_flag;//���ݰ���ʶ 0�ظ�

	/*res_type
	1:����Ԫ��ֵ�ظ���
	2 ����Ԫ��״̬�ظ���
	3 ����Ԫ����ͨ���ϻظ���
	4 ����Ԫ��״̬���ϻظ���
	5 ȡ��Ԫ����ͨ���ϻظ���
	6 ȡ��Ԫ��״̬���ϻظ���
	7 ������ϻظ���
	8 ��ȡԪ��ֵ�ظ���
	9 ��ȡԪ��״̬�ظ�*/

	byte res_type;//�ظ�����

	char cir_name[50];//Ԫ������
	byte res_val;//�ظ����ݣ���Ԫ��״̬��Ԫ��ֵ
	
	byte end;//0xab//��β
	stCsCirProtRes()
	{
		memset(this, 0, sizeof(*this));
	}
}CsCirProtRes;





#pragma pack(pop)

#endif //__CS_CIRCUIT_PROTOCOL__H__