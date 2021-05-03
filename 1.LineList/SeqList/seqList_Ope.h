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
//����ɹ�---1
//����ʧ��---0
int ListInsert(SeqList* sl,int index/*�����±꣨λ�ã�*/,int elem/*����Ԫ��*/);
//ɾ������Ԫ��
//�ɵ������������ر�ɾ��Ԫ�ص�ֵ��value��
//ɾ���ɹ�---1
//ɾ��ʧ��---0
int ListDelete(SeqList* sl,int index,int* elem);
//���Ԫ�ص�ֵ
//�ɵ������������ر�ɾ��Ԫ�ص�ֵ��value��
//��ȡ�ɹ�---1
//��ȡʧ��---0
int ListGet(SeqList* sl,int index,int* elem);

