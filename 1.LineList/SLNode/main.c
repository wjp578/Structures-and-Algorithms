#include <stdio.h>
#include <stdlib.h>
#include "SLNode_Ope.h"

int main()
{
    SNodeList sln=NULL;

    printf("---------------\n");
    printf("≥ı ºªØ≤‚ ‘\n");
    ListInitiate(&sln);
    printf("%d\n",ListLength(sln));


    printf("\n---------------\n");
    printf("≤Â»Î≥…π¶≤‚ ‘\n");
    int i=1;
    for(;i<11;i++)
        ListInsert(sln,i,i);
    ListPrint(sln);
    printf("%d\n",ListLength(sln));


    printf("\n---------------\n");
    printf("≤Â»Î ß∞‹≤‚ ‘\n");
    ListInsert(sln,13,124);
    ListPrint(sln);
    printf("%d\n",ListLength(sln));


    printf("\n---------------\n");
    printf("…æ≥˝‘™Àÿ≤‚ ‘\n");
    ListDelete(sln,5,&i);
    ListPrint(sln);
    printf("±ª…æ≥˝‘™Àÿ=%d\n",i);
    printf("%d\n",ListLength(sln));


    printf("\n---------------\n");
    printf("¡¥±Ìœ˙ªŸ≤‚ ‘\n");
    ListDestory(sln);

    return 0;
}
