#include "CycDLNode_Ope.h"

//��ʼ��
void ListInitiate(CycDLNode* head)
{
    *head=(CycDLNode)malloc(sizeof(CDLNode));
    (*head)->prior=(*head);
    (*head)->next=(*head);
}

//��ó���
int ListLength(CycDLNode head)
{
    CycDLNode p=head;
    int count=0;
    while(p->next!=head)
    {
        count++;
        p=p->next;
    }
    return count;
}

//������
//����ɹ�---1
//����ʧ��---0
int ListInsert(CycDLNode head,int pos/*��1��ʼ����λ��*/,Datatype val)
{
    int len=ListLength(head);
    if(pos>len+1)
    {
        printf("pos�����Ƿ�");
        return 0;
    }
    while(pos)
    {
        head=head->next;
        pos--;
    }
    //��ʱָ��ָ��posλ�ý��
    CycDLNode p=(CycDLNode)malloc(sizeof(CDLNode));
    p->val=val;

    p->prior=head->prior;//�����½��ǰ��
    head->prior->next=p;//�½��������ǰ�����
    p->next=head;//�����½����
    head->prior=p;//�½�������Ϻ��ǰ��
    return 1;
}

//ɾ�����
//ɾ���ɹ�---1
//ɾ��ʧ��---0
int ListDelete(CycDLNode head,int pos/*��1��ʼ����λ��*/,Datatype* ret)
{
    int len=ListLength(head);
    if(pos>len+1)
    {
        printf("pos�����Ƿ�");
        return 0;
    }
    while(pos)
    {
        head=head->next;
        pos--;
    }

    *ret=head->val;
    head->prior->next=head->next;
    head->next->prior=head->prior;
    free(head);
    head=NULL;
    return 1;
}

//��ӡ����
void ListPrint(CycDLNode head,int mode/*1---prior;2---next*/)
{
    CycDLNode p;
    switch(mode)
    {
    case 1:
        p=head->prior;
        while(p!=head)
        {
            printf("-->%d",p->val);
            p=p->prior;
        }
        printf("\n");
        break;
    case 2:
        p=head->next;
        while(p!=head)
        {
            printf("-->%d",p->val);
            p=p->next;
        }
        printf("\n");
        break;
    }
}

//���������ͷſռ�
void ListDestory(CycDLNode const head)
{
    CycDLNode p=head;
    CycDLNode q=head->next;
    while(q!=head)
    {
        free(p);
        p=q;
        q=q->next;

        printf("DestorySuccessfully ");
    }
    free(p);
    p=NULL;q=NULL;
    printf("ClearSuccessfully\n");
}
