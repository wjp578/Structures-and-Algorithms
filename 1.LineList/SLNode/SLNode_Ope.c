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

//插入元素
//插入成功---1
//插入失败---0
int ListInsert(SNodeList head,int pos,DataType elem)
{
    int len=ListLength(head);
    if(len+1<pos)
    {
        printf("输入位置非法\n");
        return 0;
    }

    int i=1;
    //假设插入位置5
    for(;i<pos;i++)
        head=head->next;
        //head指向位置4
    //p指向位置5
    SNodeList p=head->next;

    SNodeList tem=(SNodeList)malloc(sizeof(SLNode));
    tem->data=elem;
    head->next=tem;
    tem->next=p;

    return 1;
}

//删除元素
//被删除元素由第三个参数返回
//删除成功---1
//删除失败---0
int ListDelete(SNodeList head,int pos,DataType *elem)
{
    int len=ListLength(head);
    if(len+1<pos)
    {
        printf("输入位置非法\n");
        return 0;
    }

    int i=1;
    //假设删除位置5
    for(;i<pos;i++)
        head=head->next;
        //head指向位置4
    //p指向位置5
    SNodeList p=head->next;

    *elem=p->data;
    head->next=p->next;
    free(p);
    p=0;//NULL

    return 1;
}

//取出元素
//被取得元素由第三个参数返回
//取成功---1
//取失败---0
int ListGet(SNodeList head,int pos,DataType *elem)
{
    int len=ListLength(head);
    if(len+1<pos)
    {
        printf("输入位置非法\n");
        return 0;
    }

    int i=0;
    //假设被取元素位置为5
    for(;i<pos;i++)
        head=head->next;

    *elem=head->data;
    return 1;
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

//打印链表元素
void ListPrint(SNodeList head)
{
    if(head->next==0)
    {
        printf("链表无元素\n");
        return;
    }

//    head=head->next;
    while((head=head->next))//跳过头节点
        printf("-->%d",head->data);
    printf("\n");
    return;
}
