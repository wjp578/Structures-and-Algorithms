#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
}SLNode,*SNodeList;

//��ʼ��
void ListInitiate(SLNode **head);
//�󳤶�
int ListLength(SNodeList head);
//���ٵ�����
void ListDestory(SNodeList head);
