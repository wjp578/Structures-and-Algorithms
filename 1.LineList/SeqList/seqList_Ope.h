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
int ListInsert(SeqList* sl,int index/*插入下标（位置）*/,int elem/*插入元素*/);
//删除数据元素
//按位置删除
int ListDelete(SeqList* sl,int index,int* elem);
//获得元素的值
int ListGet(SeqList* sl,int index,int* elem);


//算法举例
//删除第一个值相同结点
int ListDeleteByVal(SeqList* sl,DataType val);
//删除所有值相同结点
int ListAllDeleteByVal(SeqList* sl,DataType val);

