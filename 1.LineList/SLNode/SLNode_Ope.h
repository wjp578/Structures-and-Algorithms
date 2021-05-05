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
//插入元素
int ListInsert(SNodeList head,int pos,DataType elem);
//删除元素
int ListDelete(SNodeList head,int pos,DataType *elem);
//取出元素
int ListGet(SNodeList head,int pos,DataType *elem);
//销毁单链表
void ListDestory(SNodeList head);
//打印链表元素
void ListPrint(SNodeList head);
