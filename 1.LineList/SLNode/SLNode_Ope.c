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





//排序

//回调函数
//排序依据--此时为升序
int compare_great(const void* e1,const void* e2)
{
    return (((*(sortdata*)e1).val)-((*(sortdata*)e2).val));
//    return (*((sortdata*)e1).val-*((sortdata*)e2).val);
}


//设计算法实现单链表升序排序
void ListSort_great(SNodeList* head)
{
    int len=ListLength(*head);
    sortdata* sd=(sortdata*)malloc((len+1)*sizeof(sortdata));//多申请一个空间，从1保存数据
    SNodeList p=*head;
    int i=1;

    //获得原数据和下标，存入数组
    while((p=p->next))//跳过头节点
    {
        //从1开始保存数据
        sd[i].pos=i;
        sd[i].val=p->data;
        i++;
    }
    //排序数组
    qsort(sd+1/*不排序第一个元素（sd[0]）*/,len,sizeof(sortdata),compare_great);

    //申请新链表
    SNodeList newhead;
    ListInitiate(&newhead);

    //通过数组找回原链表数据，生成新结点插入新链表
    for(i=1;i<=len;i++)
    {
        p=*head;
        int j=1;
        //找原链表data
        for(j=1;j<=sd[i].pos;j++)
            p=p->next;
        ListInsert(newhead,i,p->data/*sd[i].val*/);
    }

    //连接新链表，释放旧链表
    ListDestory(*head);
    *head=newhead;

    //释放sd数组
    free(sd);
    sd=NULL;
}

//在升序链表中按序插入数据,保持顺序
//返回值---插入位置
int LIstInsert_val(SNodeList head,DataType elem)
{
    int i=1;
    SNodeList p=head;
    //若当p=NULL而正常退出循环
    //i正常++，相对下列注释多执行一次
    //i此时为链表最后一个结点的后一个位置(listlenght()+1)
    //此时i为元素正确插入的位置
    while((p=p->next))
    {
        //若找到比elem大的元素，则提前break
        //此时少执行一次i++
        //i刚好也等于正确插入位置
        if(p->data>=elem)
            break;
        i++;
    }
    ListInsert(head,i,elem);
    return i;
}









