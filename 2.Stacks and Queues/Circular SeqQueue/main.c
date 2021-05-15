#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue_Ope.h"

int main()
{
    csqueue csq;
    CSQueue sq=&csq;
    QueueInitate(sq);

    int i;
    for(i=0;i<3;i++)
        QueueAppend(sq,i);
    QueuePrint(sq);

    for(i=0;i<3;i++)
        QueueDelete(sq,NULL);
    QueuePrint(sq);

    int ret;
    if(QueueGet(sq,&ret))
        printf("ret=%d\n",ret);

    QueuePrint(sq);
    return 0;
}
