#include "priorityQueue_Ope.h"

//检索优先级
//返回优先级最高的元素下标
//若两个优先级相同，返回优先级相同第一个元素下标
int check_greatest_priority(const PQueue *pq)
{
    int tem_priority=pq->PriQueue[0].Priority;
    int i=0,ret=0;
    for(i=1;i<pq->Qcount;i++)
    {
        if(pq->PriQueue[i].Priority < tem_priority)
        {
            tem_priority=pq->PriQueue[i].Priority;
            ret=i;
        }
    }
    return ret;
}

//初始化队列
void QueueInitate(PQueue *pq)
{
    pq->Qcount=0;
}

//入队
int QueueAppend(PQueue *pq,const QElem *qe)
{
    if(pq->Qcount==MAX_CAPACITY)
    {
        printf("full queue, fail to append\n");
        return 0;
    }

    pq->PriQueue[pq->Qcount].elem=qe->elem;
    pq->PriQueue[pq->Qcount].Priority=qe->Priority;
    pq->Qcount++;
    return 1;
}

//出队
int QueueDelete(PQueue *pq,QElem *qe)
{
    if(pq->Qcount==0)
    {
        printf("empty queue, fail to delete");
        return 0;
    }

    int pos=check_greatest_priority(pq);
    if(qe)
        memcpy(qe,&(pq->PriQueue[pos]),sizeof(QElem));

    int i=0;
    for(i=pos;i<pq->Qcount-1;i++)
        memcpy(&(pq->PriQueue[i]),
               &(pq->PriQueue[i+1]),
               sizeof(QElem));

    pq->Qcount--;
    return 1;
}

//取元素
int QueueGet(const PQueue *pq,QElem *qe)
{
    if(pq->Qcount==0)
    {
        printf("empty queue, fail to get");
        return 0;
    }

    assert(qe!=NULL);

    memcpy(qe,
           &(pq->PriQueue[check_greatest_priority(pq)]),
           sizeof(QElem));

    return 1;
}

//打印
void QueuePrint(const PQueue *pq)
{
    int i=0;
    for(i=0;i<pq->Qcount;i++)
        printf("priority %d\telem %d\n",
               pq->PriQueue[i].Priority,
               pq->PriQueue[i].elem);

    printf("\n");
}

