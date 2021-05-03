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
//打印顺序表
void ListPrint(const SeqList* sl);
//插入数据元素
//插入成功---1
//插入失败---0
int ListInsert(SeqList* sl,int index/*插入下标（位置）*/,int elem/*插入元素*/);
//删除数据元素
//由第三个参数带回被删除元素的值（value）
//删除成功---1
//删除失败---0
int ListDelete(SeqList* sl,int index,int* elem);
//获得元素的值
//由第三个参数带回被删除元素的值（value）
//获取成功---1
//获取失败---0
int ListGet(SeqList* sl,int index,int* elem);

