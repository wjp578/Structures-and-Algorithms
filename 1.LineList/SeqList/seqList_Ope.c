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

int ListInsert(SeqList* sl,int index,int elem)
{
    if(sl->sz>=MAX_LEN)
    {
        printf("˳�������\n");
        return 0;
    }

    else if(index<1||index>sl->sz+1)
        {
            printf("����λ�÷Ƿ�\n");
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

int ListDelete(SeqList* sl,int index,int* elem)
{
    if(index<1||index>sl->sz)
    {
        printf("����λ�÷Ƿ�\n");
        return 0;
    }

    //���汻ɾ��Ԫ��
    *elem=sl->arr[index-1];

    //ɾ��Ԫ��
    int i;
    for(i=index-1;i<sl->sz-1;i++)
        sl->arr[i]=sl->arr[i+1];

    //��������������������߼�sz-1����(�߼�ɾ��)
    sl->sz--;

    return 1;
}

int ListGet(SeqList* sl,int index,int* elem)
{
    if(index<1||index>sl->sz)
    {
        printf("����λ�÷Ƿ�\n");
        return 0;
    }

    *elem=sl->arr[index-1];
    return 1;

}
