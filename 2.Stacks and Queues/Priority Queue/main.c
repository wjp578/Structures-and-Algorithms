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


    //ģ����̹���
    FILE *fp=fopen(FILENAME,"r");
    while(!feof(fp))
    {
        //��ʹ�ļ�Ϊ�գ��ļ����Ի����ļ���������EOF������ʱfeof�Ὣ�ļ���Ϊ�ǿգ���Ϊ�ļ��д���EOF��
        //��ʱ����fscanf����ֵ�жϣ��÷���ֵΪ������Ԫ�ظ�������������ļ�������EOF��������-1
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
