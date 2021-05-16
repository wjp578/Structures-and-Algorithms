#include "ChQueue_Ope.h"

//初始化
void QueueInitiate(CQueue *cq)
{
    (*cq)->Qfront=NULL;
    (*cq)->Qrear=NULL;
}

//更新队空
void QueueUpdataState(CQueue *cq)
{
    if((*cq)->Qfront==NULL)
        (*cq)->Qrear=NULL;
}

//判断非空
int QueueNotEmpty(CQueue cq)
{
    if(cq->Qfront==NULL)
        return 0;
    return 1;
}

//入队
int QueueAppend(CQueue *cq,DataType val)
{
    CQNode* newnode=(CQNode*)malloc(sizeof(CQNode));
    newnode->val=val;
    newnode->next=NULL;

    if((*cq)->Qrear)
    {
        (*cq)->Qrear->next=newnode;
        (*cq)->Qrear=newnode;
        return 1;
    }

    (*cq)->Qrear=newnode;
    (*cq)->Qfront=newnode;
    return 1;
}

//出队
int QueueDelete(CQueue *cq,DataType *ret)
{
    if(!QueueNotEmpty(*cq))
    {
        printf("empty queue,fail to delete\n");
        QueueUpdataState(cq);
        return 0;
    }

    CQNode* ft=(*cq)->Qfront;
    (*cq)->Qfront=(*cq)->Qfront->next;
    if(ret)
        *ret=ft->val;
    free(ft);
    ft=NULL;

    QueueUpdataState(cq);
    return 1;
}

//取队头元素
int QueueGet(CQueue cq,DataType *ret)
{
    if(!QueueNotEmpty(cq))
    {
        printf("empty queue,fail to get\n");
        return 0;
    }

    *ret=cq->Qfront->val;
    return 1;
}

//打印
void QueuePrint(CQueue cq)
{
    CQNode* front=cq->Qfront;
    while(front)
    {
        printf("-->%d",front->val);
        front=front->next;
    }
    printf("\n");
}

//销毁
void QueueDestory(CQueue cq)
{
    if(!QueueNotEmpty(cq))
        return;

    cq->Qrear=cq->Qfront->next;
    while(cq->Qrear)
    {
        free(cq->Qfront);
        cq->Qfront=cq->Qrear;
        cq->Qrear=cq->Qrear->next;
    }

    free(cq->Qfront);
    cq->Qfront=NULL;

    if(cq->Qfront==NULL&&cq->Qrear==NULL)
        printf("destory successfully\n");
}
