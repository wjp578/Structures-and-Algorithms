#include "ChQueue_Ope.h"

//��ʼ��
void QueueInitiate(CQueue *cq)
{
    (*cq)->Qfront=NULL;
    (*cq)->Qrear=NULL;
}

//���¶ӿ�
void QueueUpdataState(CQueue *cq)
{
    if((*cq)->Qfront==NULL)
        (*cq)->Qrear=NULL;
}

//�жϷǿ�
int QueueNotEmpty(CQueue cq)
{
    if(cq->Qfront==NULL)
        return 0;
    return 1;
}

//���
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

//����
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

//ȡ��ͷԪ��
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

//��ӡ
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

//����
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
