#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "SeqStack_Ope.h"

#define MAX_SIZE 30

typedef int DataType;
typedef struct
{
    DataType Stack[MAX_SIZE];
    int top;//Ԫ�ظ���
}*SeqStack,Stack;

//ջ��ʼ��
void StackInitiate(SeqStack ss);
//�жϷǿ�
int StackNotEmpty(const SeqStack ss);
//��ջ
int StackPush(SeqStack ss,DataType val);
//��ջ
int StackPop(SeqStack ss,DataType *ret);
//ȡջ��Ԫ��
int StackTop(const SeqStack ss,DataType *ret);
//��ӡջԪ��
void StackPrint(const SeqStack ss);
