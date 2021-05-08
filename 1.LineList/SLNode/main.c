#include <stdio.h>
#include <stdlib.h>
#include "SLNode_Ope.h"
#include <time.h>

#define INSERT_COUNT 30

int main()
{
    SNodeList sln=NULL;

    printf("---------------\n");
    printf("≥ı ºªØ≤‚ ‘\n");
    ListInitiate(&sln);
    printf("%d\n",ListLength(sln));
    ListPrint(sln);


//    printf("\n---------------\n");
//    printf("≤Â»Î≥…π¶≤‚ ‘\n");
//    int i=1;
//    for(;i<INSERT_COUNT+1;i++)
//        ListInsert(sln,i,i);
//    ListPrint(sln);
//    printf("%d\n",ListLength(sln));
//
//
//    printf("\n---------------\n");
//    printf("≤Â»Î ß∞‹≤‚ ‘\n");
//    ListInsert(sln,13,124);
//    ListPrint(sln);
//    printf("%d\n",ListLength(sln));
//
//
//    printf("\n---------------\n");
//    printf("…æ≥˝‘™Àÿ≤‚ ‘\n");
//    if(ListDelete(sln,5,&i))
//        printf("±ª…æ≥˝‘™Àÿ=%d\n",i);
//    else
//        printf("…æ≥˝ ß∞‹");
//    ListPrint(sln);
//    printf("%d\n",ListLength(sln));
//
//    printf("\n---------------\n");
//    printf("»°‘™Àÿ≤‚ ‘\n");
//    if(ListGet(sln,12,&i))
//        printf("»°µ√‘™Àÿ=%d\n",i);
//    else
//        printf("»°‘™Àÿ ß∞‹");
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
    printf("¡¥±Ìœ˙ªŸ≤‚ ‘\n");
    ListDestory(sln);

    return 0;
}
