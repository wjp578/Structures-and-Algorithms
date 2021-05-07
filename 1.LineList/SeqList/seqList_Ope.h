#pragma once

typedef int DataType;
#define MAX_LEN 100

typedef struct
{
    DataType arr[MAX_LEN];
    int sz;
}SeqList;

//��ʼ��
void ListInitiate(SeqList* sl);
//�󳤶�
int ListLength(const SeqList* sl);
//��ӡ˳���
void ListPrint(const SeqList* sl);
//��������Ԫ��
int ListInsert(SeqList* sl,int index/*�����±꣨λ�ã�*/,int elem/*����Ԫ��*/);
//ɾ������Ԫ��
//��λ��ɾ��
int ListDelete(SeqList* sl,int index,int* elem);
//���Ԫ�ص�ֵ
int ListGet(SeqList* sl,int index,int* elem);


//�㷨����
//ɾ����һ��ֵ��ͬ���
int ListDeleteByVal(SeqList* sl,DataType val);
//ɾ������ֵ��ͬ���
int ListAllDeleteByVal(SeqList* sl,DataType val);

