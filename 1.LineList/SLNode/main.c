#include <stdio.h>
#include <stdlib.h>
#include "SLNode_Ope.h"

int main()
{
    SNodeList sln=NULL;

    printf("---------------\n");
    printf("��ʼ������\n");
    ListInitiate(&sln);
    printf("%d\n",ListLength(sln));


    printf("\n---------------\n");
    printf("����ɹ�����\n");
    int i=1;
    for(;i<11;i++)
        ListInsert(sln,i,i);
    ListPrint(sln);
    printf("%d\n",ListLength(sln));


    printf("\n---------------\n");
    printf("����ʧ�ܲ���\n");
    ListInsert(sln,13,124);
    ListPrint(sln);
    printf("%d\n",ListLength(sln));


    printf("\n---------------\n");
    printf("ɾ��Ԫ�ز���\n");
    ListDelete(sln,5,&i);
    ListPrint(sln);
    printf("��ɾ��Ԫ��=%d\n",i);
    printf("%d\n",ListLength(sln));


    printf("\n---------------\n");
    printf("�������ٲ���\n");
    ListDestory(sln);

    return 0;
}
