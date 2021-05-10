#include "ChStack_Ope.h"

//Á´Õ»³õÊ¼»¯
void StackInitiate(CStack *head)
{
    *head=(CStack)malloc(sizeof(struct CS));
    (*head)->next=NULL;
}

//ÅÐ¶Ï·Ç¿Õ
//¿Õ---0
//·Ç¿Õ---1
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

//ÈëÕ»
//³É¹¦---1
//Ê§°Ü---0
int StackInsert(CStack head,DataType val)
{

}

//´òÓ¡º¯Êý
void StackPrint(CStack head)
{
    if(!StackNotEmpty(head))
        return;

    //´ÓÕ»¶¥µ½Õ»µ×
    while((head=head->next))
        printf("-->%d",head->val);
}

//Ïú»ÙÁ´Õ»
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
