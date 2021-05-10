#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct CS
{
    DataType val;
    struct CS *next;
}*CStack;

//��ջ��ʼ��
void StackInitiate(CStack *head);
//�жϷǿ�
int StackNotEmpty(CStack head);
//��ջ
void StackPush(CStack head,DataType val);
//��ջ
int StackPop(CStack head,DataType *ret);
//ȡջ��Ԫ��
int StackTop(CStack head);
//��ӡ����
void StackPrint(CStack head);
//������ջ
void StackDestory(CStack head);
