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
