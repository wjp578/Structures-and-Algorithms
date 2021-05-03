#include <stdio.h>
#include <stdlib.h>
#include "seqList_Ope.h"

int main()
{
    SeqList l;
    ListInitiate(&l);

//    if(!ListInsert(&l,1,8))
//        printf("����ʧ�ܣ���\n");
//    ListInsert(&l,2,8);//�������

    int i,x;
    while(scanf("%d%d",&i,&x)!=EOF)
    {
        if(!ListInsert(&l,i,x))
            printf("����ʧ�ܣ���\n");
    }
    ListPrint(&l);
    printf("l.size=%d\n",ListLength(&l));

    ListDelete(&l,2,&x);
    ListPrint(&l);
    printf("delete=%d\n",x);
    printf("l.size=%d\n",ListLength(&l));

    if(!ListGet(&l,3,&x))
        printf("��ȡֵʧ��\n");
    else
        printf("get=%d",x);

    return 0;
}
