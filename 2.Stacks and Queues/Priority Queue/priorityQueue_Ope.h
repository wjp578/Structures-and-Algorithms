#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CAPACITY 100

typedef int DataType;

typedef struct QueueElem//�������ȼ�+Ԫ��
{
    DataType elem;
    int Priority;
}QElem;

typedef struct PriorityQueue//�������
{
    QElem PriQueue[MAX_CAPACITY];
    int Qcount;
}PQueue;

//��ʼ������
void QueueInitate(PQueue *pq);
//���
int QueueAppend(PQueue *pq,const QElem *qe);
//����
int QueueDelete(PQueue *pq,QElem *qe);
//ȡԪ��
int QueueGet(const PQueue *pq,QElem *qe);
//��ӡ
void QueuePrint(const PQueue *pq);
