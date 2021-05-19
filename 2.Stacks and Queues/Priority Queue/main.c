#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue_Ope.h"

#define FILENAME "Simulation process.txt"

int main()
{
    //test
    PQueue pq;
    QElem qe;
    QueueInitate(&pq);

//    qe.elem=10;
//    qe.Priority=4;
//    QueueAppend(&pq,&qe);
//    qe.Priority=1;
//    QueueAppend(&pq,&qe);
//    QueuePrint(&pq);
//
//    QueueDelete(&pq,NULL);
//    QueuePrint(&pq);


    //模拟进程管理
    FILE *fp=fopen(FILENAME,"r");
    while(!feof(fp))
    {
        //即使文件为空，文件中仍会有文件结束符（EOF），此时feof会将文件判为非空（因为文件中存在EOF）
        //此时依靠fscanf返回值判断，该返回值为读到的元素个数，如果读到文件结束（EOF），返回-1
        int i=fscanf(fp,"%d%d",&(qe.Priority),&(qe.elem));
        if(i==-1)
            break;
        QueueAppend(&pq,&qe);
    }

    QueuePrint(&pq);
    while(pq.Qcount!=0)
    {
        QueueDelete(&pq,&qe);
        printf("priority %d\telem %d\n",qe.Priority,qe.elem);
    }

    fclose(fp);
    fp=NULL;

    return 0;
}
