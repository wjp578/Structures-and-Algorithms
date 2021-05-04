#include "SLNode_Ope.h"

//初始化链表，带头结点
void ListInitiate(SLNode **head/* SNodeList head */)
{
    *head=(SNodeList)malloc(sizeof(SLNode));
    (*head)->next=NULL;
}

//求链表长度，不计算头节点长度(-1)
//返回链表长度
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

//销毁单链表
void ListDestory(SNodeList head)
{
    //销毁前n-1个元素
    SNodeList newhead=head->next;
    while(newhead)
    {
        free(head);
        head=newhead;
        newhead=newhead->next;
    }
    //销毁第n个元素
    free(head);
    head=NULL;

    if(head==NULL&&newhead==NULL)
        //测试
        printf("Destory Successfully\n");
}
