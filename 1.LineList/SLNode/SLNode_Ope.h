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
//����Ԫ��
int ListInsert(SNodeList head,int pos,DataType elem);
//ɾ��Ԫ��
int ListDelete(SNodeList head,int pos,DataType *elem);
//ȡ��Ԫ��
int ListGet(SNodeList head,int pos,DataType *elem);
//���ٵ�����
void ListDestory(SNodeList head);
//��ӡ����Ԫ��
void ListPrint(SNodeList head);
