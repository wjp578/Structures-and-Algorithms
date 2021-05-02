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
    return 1;
}
