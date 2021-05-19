#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CAPACITY 100

typedef int DataType;

typedef struct QueueElem//定义优先级+元素
{
    DataType elem;
    int Priority;
}QElem;

typedef struct PriorityQueue//定义队列
{
    QElem PriQueue[MAX_CAPACITY];
    int Qcount;
}PQueue;

//初始化队列
void QueueInitate(PQueue *pq);
//入队
int QueueAppend(PQueue *pq,const QElem *qe);
//出队
int QueueDelete(PQueue *pq,QElem *qe);
//取元素
int QueueGet(const PQueue *pq,QElem *qe);
//打印
void QueuePrint(const PQueue *pq);
