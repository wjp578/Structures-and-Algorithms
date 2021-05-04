#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
}SLNode,*SNodeList;

//初始化
void ListInitiate(SLNode **head);
//求长度
int ListLength(SNodeList head);
//销毁单链表
void ListDestory(SNodeList head);
