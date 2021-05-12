#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
typedef struct CS
{
    DataType val;
    struct CS *next;
}*CStack;

//链栈初始化
void StackInitiate(CStack *head);
//判断非空
int StackNotEmpty(CStack head);
//入栈
void StackPush(CStack head,DataType val);
//出栈
int StackPop(CStack head,DataType *ret);
//取栈顶元素
DataType StackTop(CStack head);
//打印函数
void StackPrint(CStack head);
//销毁链栈
void StackDestory(CStack head);
