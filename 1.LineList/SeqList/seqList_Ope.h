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
//插入数据元素
//插入成功---1
//插入失败---0
int ListInsert(SeqList* sl,int index/*插入下标（位置）*/,int elem/*插入元素*/);

