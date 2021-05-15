#include "SeqQueue_Ope.h"

//��ʼ��
void QueueInitate(CSQueue sq)
{
    sq->Qfront=0;
    sq->Qrear=0;
    sq->Qcount=0;
}

//���зǿ�
//�ǿ�---1
//��  ---0
int QueueNotEmpty(CSQueue sq)
{
    if(sq->Qcount==0)
        return 0;
    return 1;
}

//���
//�ɹ�---1
//ʧ��---0
int QueueAppend(CSQueue sq,Datatype val)
{
    if(sq->Qcount==MAX_CAPACITY)
    {
        printf("full queue\n");
        return 0;
    }

    sq->CSQueArr[sq->Qfront]=val;
    sq->Qcount++;
    sq->Qfront++;

    if(sq->Qfront==MAX_CAPACITY)
        sq->Qfront=0;

    return 1;
}

//����
//�ɹ�---1
//ʧ��---0
int QueueDelete(CSQueue sq,Datatype *ret)
{
    if(!QueueNotEmpty(sq))
    {
        printf("empty queue\n");
        return 0;
    }

    if(ret)
        *ret=sq->CSQueArr[sq->Qfront];
    sq->Qcount--;
    sq->Qfront++;

    if(sq->Qrear==MAX_CAPACITY)
        sq->Qrear=0;

    return 1;
}

//ȡ��ͷԪ��
//�ɹ�---1
//ʧ��---0
int QueueGet(CSQueue sq,Datatype *ret)
{
    if(!QueueNotEmpty(sq))
    {
        printf("empty queue\n");
        return 0;
    }

    if(ret)
        *ret=sq->CSQueArr[sq->Qfront];

    return 1;
}

//��ӡ
void QueuePrint(CSQueue sq)
{
    int count=sq->Qcount;
//    int front=sq->Qfront;
    int rear=sq->Qrear;

    while(1)
    {
        if(count==0)
            {
                printf("\n");
                return;
            }

        if(rear==MAX_CAPACITY)
            rear=0;

        printf("-->%d",sq->CSQueArr[rear++]);
        count--;
    }
}
