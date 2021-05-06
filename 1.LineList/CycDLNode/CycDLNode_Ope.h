#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;
typedef struct LNode//˫��ѭ������
{
    Datatype val;
    struct LNode* prior;
    struct LNode* next;
}CDLNode,*CycDLNode;

//��ʼ��
void ListInitiate(CycDLNode* head);
//��ó���
int ListLength(CycDLNode head);
//������
int ListInsert(CycDLNode head,int pos/*��1��ʼ����λ��*/,Datatype val);
//ɾ�����
int ListDelete(CycDLNode head,int pos/*��1��ʼ����λ��*/,Datatype* ret);
//��ӡ����
void ListPrint(CycDLNode head,int mode/*1---prior;2---next*/);
//���������ͷſռ�
void ListDestory(CycDLNode const head);


