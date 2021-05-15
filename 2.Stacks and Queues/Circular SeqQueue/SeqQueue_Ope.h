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

//初始化
void QueueInitate(CSQueue sq);
//队列非空
int QueueNotEmpty(CSQueue sq);
//入队
int QueueAppend(CSQueue sq,Datatype val);
//出队
int QueueDelete(CSQueue sq,Datatype *ret);
//取队头元素
 int QueueGet(CSQueue sq,Datatype *ret);
 //打印
void QueuePrint(CSQueue sq);
