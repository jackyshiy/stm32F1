/**
  ******************************************************************************
  * @file    ringbuff.h 
  * @author  alan
  * @version V1.2.0
  * @date    
  * @brief   ringbuff manage module
  ******************************************************************************
  * @attention
  ******************************************************************************
*/
#ifndef RINGBUFF_H
#define RINGBUFF_H

#include "includes.h"

#define RING_BUFF_WATERMARK	0xAA	//����ˮӡ

typedef enum
{
	RingbuffEmpty=0,		//�����
	RingbuffFull,			//������
	RingbuffNotFull			//�������
}RingbuffStatus_t;

typedef enum
{
	RingbuffOpSucess=0,		//��������ɹ�----��ȡд�뻺��
	RingbuffOpFailure,		//�������ʧ��----��ȡд�뻺��
	RingbuffOpNotInit
}RingbuffOperateResult_t;

typedef struct
{
	u8 UsePercent;			//����ʱ��ٷֱ�
	u8 MemberSize;			//�����Ա��С��1�ֽڡ�2�ֽڡ�4�ֽ�
	u8 clearEnableFlag;		//��ȡ����ʱ��ֵΪTRUE�����㻺��/
	void *pBuff;			//ָ�򻺴��ָ��
	u8 status;				//����״̬
	u16 inBuffPointer;		//�������ָ��
	u16 OutBuffPointer;		//�������ָ��
	u16 usedBytes;			//�������������ʹ��	
	u16 freeBytesSize;		//�����������ʣ��
	u16 totalByteSize;		//������������ܴ�С
}RingbuffMgr_t;

// -------------------------------------- �ϲ�Ͳ���ú��� --------------------------------------
u8 getRingbuffStatus(RingbuffMgr_t *Ringbuff);
u16 getRingbuffUseSize(RingbuffMgr_t *Ringbuff);
u16 getRingbuffFreeSize(RingbuffMgr_t *Ringbuff);
void setRingbuffClearFlag(RingbuffMgr_t *Ringbuff,u8 flag);
// -------------------------------------- �ϲ���ú��� --------------------------------------
void ringbuffInit(RingbuffMgr_t *Ringbuff,void *buff,u16 BuffByteSize,u8 MemberSize,u8 clearFlag);
void resetRingBuff(RingbuffMgr_t *Ringbuff);
RingbuffOperateResult_t readOneMemberFromRingbuff(RingbuffMgr_t *Ringbuff,void *data);
// -------------------------------------- �ײ���ú��� --------------------------------------
RingbuffOperateResult_t writeOneMemberToRingbuff(RingbuffMgr_t *Ringbuff,void *data);
RingbuffOperateResult_t writeNMemberToRingbuff(RingbuffMgr_t *Ringbuff,void *pbuff,u16 WriteByteSize);
u8 CalRingbuffUsedPercent(RingbuffMgr_t *Ringbuff);
// -------------------------------------- �������Թ��� --------------------------------------

void printRingBuff(RingbuffMgr_t *Ringbuff,u8 printDataFlag);
void ringbuffTest(void);


#endif 



