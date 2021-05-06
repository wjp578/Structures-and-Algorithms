#include "CycDLNode_Ope.h"

//初始化
void ListInitiate(CycDLNode* head)
{
    *head=(CycDLNode)malloc(sizeof(CDLNode));
    (*head)->prior=(*head);
    (*head)->next=(*head);
}

//获得长度
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

//插入结点
//插入成功---1
//插入失败---0
int ListInsert(CycDLNode head,int pos/*从1开始计算位置*/,Datatype val)
{
    int len=ListLength(head);
    if(pos>len+1)
    {
        printf("pos参数非法");
        return 0;
    }
    while(pos)
    {
        head=head->next;
        pos--;
    }
    //此时指针指向pos位置结点
    CycDLNode p=(CycDLNode)malloc(sizeof(CDLNode));
    p->val=val;

    p->prior=head->prior;//连接新结点前驱
    head->prior->next=p;//新结点连接老前驱后继
    p->next=head;//连接新结点后继
    head->prior=p;//新结点连接老后继前驱
    return 1;
}

//删除结点
//删除成功---1
//删除失败---0
int ListDelete(CycDLNode head,int pos/*从1开始计算位置*/,Datatype* ret)
{
    int len=ListLength(head);
    if(pos>len+1)
    {
        printf("pos参数非法");
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

//打印链表
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

//销毁链表，释放空间
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
