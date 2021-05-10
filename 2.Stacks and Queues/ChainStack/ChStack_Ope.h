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
int StackInsert(CStack head,DataType val);
//��ӡ����
void StackPrint(CStack head);
//������ջ
void StackDestory(CStack head);
