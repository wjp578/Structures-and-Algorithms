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
    printf("stack not empty\n");
    return 1;
}

//��ջ
//�ɹ�---1
//ʧ��---0
int StackInsert(CStack head,DataType val)
{

}

//��ӡ����
void StackPrint(CStack head)
{
    if(!StackNotEmpty(head))
        return;

    //��ջ����ջ��
    while((head=head->next))
        printf("-->%d",head->val);
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
