#include <stdio.h>
#include <stdlib.h>
#include "CycDLNode_Ope.h"

int main()
{
    CycDLNode head;
    ListInitiate(&head);
    printf("%d\n",ListLength(head));

    int i=1;
    for(;i<=10;i++)
        ListInsert(head,i,i);
    ListInsert(head,6,4);
    printf("%d\n",ListLength(head));
    ListPrint(head,1);
    ListPrint(head,2);

    ListDelete(head,1,&i);
    printf("±»É¾³ýµÄÔªËØ=%d\n",i);
    printf("%d\n",ListLength(head));
    ListPrint(head,1);
    ListPrint(head,2);


    ListDestory(head);
    return 0;
}
