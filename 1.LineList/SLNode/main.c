#include <stdio.h>
#include <stdlib.h>
#include "SLNode_Ope.h"
#include <time.h>

#define INSERT_COUNT 30

int main()
{
    SNodeList sln=NULL;

    printf("---------------\n");
    printf("��ʼ������\n");
    ListInitiate(&sln);
    printf("%d\n",ListLength(sln));
    ListPrint(sln);


//    printf("\n---------------\n");
//    printf("����ɹ�����\n");
//    int i=1;
//    for(;i<INSERT_COUNT+1;i++)
//        ListInsert(sln,i,i);
//    ListPrint(sln);
//    printf("%d\n",ListLength(sln));
//
//
//    printf("\n---------------\n");
//    printf("����ʧ�ܲ���\n");
//    ListInsert(sln,13,124);
//    ListPrint(sln);
//    printf("%d\n",ListLength(sln));
//
//
//    printf("\n---------------\n");
//    printf("ɾ��Ԫ�ز���\n");
//    if(ListDelete(sln,5,&i))
//        printf("��ɾ��Ԫ��=%d\n",i);
//    else
//        printf("ɾ��ʧ��");
//    ListPrint(sln);
//    printf("%d\n",ListLength(sln));
//
//    printf("\n---------------\n");
//    printf("ȡԪ�ز���\n");
//    if(ListGet(sln,12,&i))
//        printf("ȡ��Ԫ��=%d\n",i);
//    else
//        printf("ȡԪ��ʧ��");
//    ListPrint(sln);


    srand((unsigned)time(NULL));
    int i=1;
    for(;i<INSERT_COUNT+1;i++)
        ListInsert(sln,i,rand()%10);
    ListPrint(sln);

    ListSort_great(&sln);
    ListPrint(sln);

    printf("insert_pos=%d\n",LIstInsert_val(sln,5));
    ListPrint(sln);

    printf("\n---------------\n");
    printf("�������ٲ���\n");
    ListDestory(sln);

    return 0;
}
