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

