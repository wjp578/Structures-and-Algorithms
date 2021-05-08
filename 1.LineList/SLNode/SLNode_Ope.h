#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
}SLNode,*SNodeList;

typedef struct
{
    int pos;
    DataType val;
}sortdata;

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


//�㷨��ƾ���
//����㷨ʵ�ֵ�������������
void ListSort_great(SNodeList* head);
//�����������а����������,����˳��
int LIstInsert_val(SNodeList head,DataType elem);
