#include <stdio.h>
#include <stdlib.h>
#include "ChQueue_Ope.h"

int main()
{
    cqueue cqu;
    CQueue cq=&cqu;
    QueueInitiate(&cq);

    int i=0;
    for(i=0;i<3;i++)
        QueueAppend(&cq,i+3);
    QueuePrint(cq);

    QueueDelete(&cq,NULL);
    QueueDelete(&cq,NULL);
    QueueDelete(&cq,NULL);
    QueueDelete(&cq,NULL);

    QueueGet(cq,&i);
    printf("get=%d\n",i);
    QueuePrint(cq);

    for(;i<10;i++)
        QueueAppend(&cq,i);
    QueuePrint(cq);


    QueueDestory(cq);
    return 0;
}
