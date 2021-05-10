#include "ChStack_Ope.h"

//链栈初始化
void StackInitiate(CStack *head)
{
    *head=(CStack)malloc(sizeof(struct CS));
    (*head)->next=NULL;
}

//判断非空
//空---0
//非空---1
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

//入栈
void StackPush(CStack head,DataType val)
{
    CStack head_next=head->next;
    CStack top=(CStack)malloc(sizeof(struct CS));
    top->val=val;
    head->next=top;
    top->next=head_next;
}

//出栈
//成功--1
//失败--0
//第二个变量用于返回出栈元素的值
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

//取栈顶元素
//直接返回栈顶元素
int StackTop(CStack head)
{
    if(!StackNotEmpty(head))
        return 0;

    return head->next->val;
}

//打印函数
void StackPrint(CStack head)
{
    if(!StackNotEmpty(head))
        return;

    //从栈顶到栈底
    while((head=head->next))
        printf("-->%d",head->val);
    printf("\n");
}

//销毁链栈
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
