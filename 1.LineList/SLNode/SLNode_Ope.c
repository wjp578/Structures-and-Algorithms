#include "SLNode_Ope.h"

//��ʼ��������ͷ���
void ListInitiate(SLNode **head/* SNodeList head */)
{
    *head=(SNodeList)malloc(sizeof(SLNode));
    (*head)->next=NULL;
}

//�������ȣ�������ͷ�ڵ㳤��(-1)
//����������
int ListLength(SNodeList head)
{
    int count=0;
    SLNode *p=head;
    while(p->next!=NULL)
    {
        count++;
        p=p->next;
    }

    return count;
}

//����Ԫ��
//����ɹ�---1
//����ʧ��---0
int ListInsert(SNodeList head,int pos,DataType elem)
{
    int len=ListLength(head);
    if(len+1<pos)
    {
        printf("����λ�÷Ƿ�\n");
        return 0;
    }

    int i=1;
    //�������λ��5
    for(;i<pos;i++)
        head=head->next;
        //headָ��λ��4
    //pָ��λ��5
    SNodeList p=head->next;

    SNodeList tem=(SNodeList)malloc(sizeof(SLNode));
    tem->data=elem;
    head->next=tem;
    tem->next=p;

    return 1;
}

//ɾ��Ԫ��
//��ɾ��Ԫ���ɵ�������������
//ɾ���ɹ�---1
//ɾ��ʧ��---0
int ListDelete(SNodeList head,int pos,DataType *elem)
{
    int len=ListLength(head);
    if(len+1<pos)
    {
        printf("����λ�÷Ƿ�\n");
        return 0;
    }

    int i=1;
    //����ɾ��λ��5
    for(;i<pos;i++)
        head=head->next;
        //headָ��λ��4
    //pָ��λ��5
    SNodeList p=head->next;

    *elem=p->data;
    head->next=p->next;
    free(p);
    p=0;//NULL

    return 1;
}

//ȡ��Ԫ��
//��ȡ��Ԫ���ɵ�������������
//ȡ�ɹ�---1
//ȡʧ��---0
int ListGet(SNodeList head,int pos,DataType *elem)
{
    int len=ListLength(head);
    if(len+1<pos)
    {
        printf("����λ�÷Ƿ�\n");
        return 0;
    }

    int i=0;
    //���豻ȡԪ��λ��Ϊ5
    for(;i<pos;i++)
        head=head->next;

    *elem=head->data;
    return 1;
}

//���ٵ�����
void ListDestory(SNodeList head)
{
    //����ǰn-1��Ԫ��
    SNodeList newhead=head->next;
    while(newhead)
    {
        free(head);
        head=newhead;
        newhead=newhead->next;
    }
    //���ٵ�n��Ԫ��
    free(head);
    head=NULL;

    if(head==NULL&&newhead==NULL)
        //����
        printf("Destory Successfully\n");
}

//��ӡ����Ԫ��
void ListPrint(SNodeList head)
{
    if(head->next==0)
    {
        printf("������Ԫ��\n");
        return;
    }

//    head=head->next;
    while((head=head->next))//����ͷ�ڵ�
        printf("-->%d",head->data);
    printf("\n");
    return;
}
