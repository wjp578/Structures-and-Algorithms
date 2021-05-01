#pragma once

typedef int DataType;
#define MAX_LEN 100

typedef struct
{
    DataType arr[MAX_LEN];
    int sz;
}SeqList;

//初始化
void ListInitiate(SeqList* sl);
//求长度
int ListLength(const SeqList* sl);

