#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "ChQueue_Ope.h"
typedef int DataType;

typedef struct CQN
{
    DataType val;
    struct CQN *next;
}CQNode;

typedef struct ChainQueue
{
    CQNode *Qfront;
    CQNode *Qrear;
}cqueue,*CQueue;



//��ʼ��
void QueueInitiate(CQueue *cq);
//���¶ӿ�
void QueueUpdataState(CQueue *cq);
//�жϷǿ�
int QueueNotEmpty(CQueue cq);
//���
int QueueAppend(CQueue *cq,DataType val);
//����
int QueueDelete(CQueue *cq,DataType *ret);
//ȡ��ͷԪ��
int QueueGet(CQueue cq,DataType *ret);
//��ӡ
void QueuePrint(CQueue cq);
//����
void QueueDestory(CQueue cq);

