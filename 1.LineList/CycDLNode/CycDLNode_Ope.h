#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;
typedef struct LNode//双向循环链表
{
    Datatype val;
    struct LNode* prior;
    struct LNode* next;
}CDLNode,*CycDLNode;

//初始化
void ListInitiate(CycDLNode* head);
//获得长度
int ListLength(CycDLNode head);
//插入结点
int ListInsert(CycDLNode head,int pos/*从1开始计算位置*/,Datatype val);
//删除结点
int ListDelete(CycDLNode head,int pos/*从1开始计算位置*/,Datatype* ret);
//打印链表
void ListPrint(CycDLNode head,int mode/*1---prior;2---next*/);
//销毁链表，释放空间
void ListDestory(CycDLNode const head);


