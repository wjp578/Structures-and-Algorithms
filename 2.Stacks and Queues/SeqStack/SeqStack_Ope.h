#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "SeqStack_Ope.h"

#define MAX_SIZE 30

typedef int DataType;
typedef struct
{
    DataType Stack[MAX_SIZE];
    int top;//元素个数
}*SeqStack,Stack;

//栈初始化
void StackInitiate(SeqStack ss);
//判断非空
int StackNotEmpty(const SeqStack ss);
//入栈
int StackPush(SeqStack ss,DataType val);
//出栈
int StackPop(SeqStack ss,DataType *ret);
//取栈顶元素
int StackTop(const SeqStack ss,DataType *ret);
//打印栈元素
void StackPrint(const SeqStack ss);
