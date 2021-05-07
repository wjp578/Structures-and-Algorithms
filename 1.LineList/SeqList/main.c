#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seqList_Ope.h"

int main()
{
    SeqList l;
    srand((unsigned)time(NULL));
    ListInitiate(&l);

//    if(!ListInsert(&l,1,8))
//        printf("≤Â»Î ß∞‹£°£°\n");
//    ListInsert(&l,2,8);//≤Â»Î≤‚ ‘

    int i,x;
//    while(scanf("%d%d",&i,&x)!=EOF)
//    {
//        if(!ListInsert(&l,i,x))
//            printf("≤Â»Î ß∞‹£°£°\n");
//    }
//
//    ListPrint(&l);
//    printf("l.size=%d\n",ListLength(&l));
//
//    ListDelete(&l,2,&x);
//    ListPrint(&l);
//    printf("delete=%d\n",x);
//    printf("l.size=%d\n",ListLength(&l));
//
//    if(!ListGet(&l,3,&x))
//        printf("ªÒ»°÷µ ß∞‹\n");
//    else
//        printf("get=%d",x);



    for(i=1;i<=20;i++)
    {
        if(!ListInsert(&l,i,3))//rand()%5+1))
            printf("≤Â»Î ß∞‹£°£°\n");
    }
    ListPrint(&l);
    printf("l.size=%d\n",ListLength(&l));

//    ListDeleteByVal(&l,3);
    ListAllDeleteByVal(&l,3);
    ListPrint(&l);
    printf("l.size=%d\n",ListLength(&l));

    return 0;
}
