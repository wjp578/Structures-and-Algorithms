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



//初始化
void QueueInitiate(CQueue *cq);
//更新队空
void QueueUpdataState(CQueue *cq);
//判断非空
int QueueNotEmpty(CQueue cq);
//入队
int QueueAppend(CQueue *cq,DataType val);
//出队
int QueueDelete(CQueue *cq,DataType *ret);
//取队头元素
int QueueGet(CQueue cq,DataType *ret);
//打印
void QueuePrint(CQueue cq);
//销毁
void QueueDestory(CQueue cq);

