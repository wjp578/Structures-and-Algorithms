#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 2

typedef int Datatype;

typedef struct
{
    int Qfront;
    int Qrear;
    int Qcount;
    Datatype CSQueArr[MAX_CAPACITY];
}csqueue,*CSQueue;

//��ʼ��
void QueueInitate(CSQueue sq);
//���зǿ�
int QueueNotEmpty(CSQueue sq);
//���
int QueueAppend(CSQueue sq,Datatype val);
//����
int QueueDelete(CSQueue sq,Datatype *ret);
//ȡ��ͷԪ��
 int QueueGet(CSQueue sq,Datatype *ret);
 //��ӡ
void QueuePrint(CSQueue sq);
