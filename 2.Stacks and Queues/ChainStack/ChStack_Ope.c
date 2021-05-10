#include "ChStack_Ope.h"

//��ջ��ʼ��
void StackInitiate(CStack *head)
{
    *head=(CStack)malloc(sizeof(struct CS));
    (*head)->next=NULL;
}

//�жϷǿ�
//��---0
//�ǿ�---1
int StackNotEmpty(CStack head)
{
    if(head->next==0)
    {
        printf("stack is empty\n");
        return 0;
    }
//    printf("stack not empty\n");
    return 1;
}

//��ջ
void StackPush(CStack head,DataType val)
{
    CStack head_next=head->next;
    CStack top=(CStack)malloc(sizeof(struct CS));
    top->val=val;
    head->next=top;
    top->next=head_next;
}

//��ջ
//�ɹ�--1
//ʧ��--0
//�ڶ����������ڷ��س�ջԪ�ص�ֵ
int StackPop(CStack head,DataType *ret)
{
    if(!StackNotEmpty(head))
        return 0;

    CStack PopNode=head->next;
    if(ret!=NULL)
        *ret=PopNode->val;
    head->next=PopNode->next;
    free(PopNode);
    PopNode=NULL;
    return 1;
}

//ȡջ��Ԫ��
//ֱ�ӷ���ջ��Ԫ��
int StackTop(CStack head)
{
    if(!StackNotEmpty(head))
        return 0;

    return head->next->val;
}

//��ӡ����
void StackPrint(CStack head)
{
    if(!StackNotEmpty(head))
        return;

    //��ջ����ջ��
    while((head=head->next))
        printf("-->%d",head->val);
    printf("\n");
}

//������ջ
void StackDestory(CStack head)
{
    CStack next;
    while(head)
    {
        next=head->next;
        free(head);
        head=next;
    }
//        free(head);
    if(head==NULL)
        printf("destory successfully\n");
}
