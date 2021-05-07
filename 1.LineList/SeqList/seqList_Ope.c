#include <stdio.h>
#include <stdlib.h>
#include "seqList_Ope.h"

void ListInitiate(SeqList* sl)
{
    sl->sz=0;
}

int ListLength(const SeqList* sl)
{
    return sl->sz;
}

void ListPrint(const SeqList* sl)
{
    int i=0;
    while(i<sl->sz)
    {
        printf("%d  ",sl->arr[i]);
        i++;
    }
    printf("\n");
}

//插入成功---1
//插入失败---0
int ListInsert(SeqList* sl,int index,int elem)
{
    if(sl->sz>=MAX_LEN)
    {
        printf("顺序表已满\n");
        return 0;
    }

    else if(index<1||index>sl->sz+1)
        {
            printf("输入位置非法\n");
            return 0;
        }


    int i;
    for(i=sl->sz-1;i>index-2;i--)
    {
        sl->arr[i+1]=sl->arr[i];
    }
    sl->arr[i+1]=elem;
    sl->sz++;
    printf("successfully\n");
    return 1;
}

//删除数据元素
//按位置删除
//由第三个参数带回被删除元素的值（value）
//删除成功---1
//删除失败---0
int ListDelete(SeqList* sl,int index,int* elem)
{
    if(index<1||index>sl->sz)
    {
        printf("输入位置非法\n");
        return 0;
    }

    //保存被删除元素
    if(elem!=NULL)
    *elem=sl->arr[index-1];

    //删除元素
    int i;
    for(i=index-1;i<sl->sz-1;i++)
        sl->arr[i]=sl->arr[i+1];

    //多出来的数据无需清理，逻辑sz-1即可(逻辑删除)
    sl->sz--;

    return 1;
}

//获得元素的值
//由第三个参数带回被删除元素的值（value）
//获取成功---1
//获取失败---0
int ListGet(SeqList* sl,int index,int* elem)
{
    if(index<1||index>sl->sz)
    {
        printf("输入位置非法\n");
        return 0;
    }

    *elem=sl->arr[index-1];
    return 1;

}







//删除第一个值相同结点
//删除成功---1
//删除失败---0
int ListDeleteByVal(SeqList* sl,DataType val)
{
    int i=1,flag=0;
    for(;i<=ListLength(sl);i++)
    {
        if(sl->arr[i-1]==val)
        {
            ListDelete(sl,i,NULL);
            //delete已将结点数-1.无需再--；
            flag=1;
            break;
        }
    }
    return flag;
}

//删除所有值相同结点
//删除成功---1
//删除失败---0
int ListAllDeleteByVal(SeqList* sl,DataType val)
{
    int i=1,flag=0;
    for(;i<=ListLength(sl);i++)
    {
        if(sl->arr[i-1]==val)
        {
            ListDelete(sl,i,NULL);
            //delete已将结点数-1.无需再--；
            flag=1;
            i--;
        }
    }
    return flag;
}

