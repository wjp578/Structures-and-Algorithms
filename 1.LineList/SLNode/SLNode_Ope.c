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





//����

//�ص�����
//��������--��ʱΪ����
int compare_great(const void* e1,const void* e2)
{
    return (((*(sortdata*)e1).val)-((*(sortdata*)e2).val));
//    return (*((sortdata*)e1).val-*((sortdata*)e2).val);
}


//����㷨ʵ�ֵ�������������
void ListSort_great(SNodeList* head)
{
    int len=ListLength(*head);
    sortdata* sd=(sortdata*)malloc((len+1)*sizeof(sortdata));//������һ���ռ䣬��1��������
    SNodeList p=*head;
    int i=1;

    //���ԭ���ݺ��±꣬��������
    while((p=p->next))//����ͷ�ڵ�
    {
        //��1��ʼ��������
        sd[i].pos=i;
        sd[i].val=p->data;
        i++;
    }
    //��������
    qsort(sd+1/*�������һ��Ԫ�أ�sd[0]��*/,len,sizeof(sortdata),compare_great);

    //����������
    SNodeList newhead;
    ListInitiate(&newhead);

    //ͨ�������һ�ԭ�������ݣ������½�����������
    for(i=1;i<=len;i++)
    {
        p=*head;
        int j=1;
        //��ԭ����data
        for(j=1;j<=sd[i].pos;j++)
            p=p->next;
        ListInsert(newhead,i,p->data/*sd[i].val*/);
    }

    //�����������ͷž�����
    ListDestory(*head);
    *head=newhead;

    //�ͷ�sd����
    free(sd);
    sd=NULL;
}

//�����������а����������,����˳��
//����ֵ---����λ��
int LIstInsert_val(SNodeList head,DataType elem)
{
    int i=1;
    SNodeList p=head;
    //����p=NULL�������˳�ѭ��
    //i����++���������ע�Ͷ�ִ��һ��
    //i��ʱΪ�������һ�����ĺ�һ��λ��(listlenght()+1)
    //��ʱiΪԪ����ȷ�����λ��
    while((p=p->next))
    {
        //���ҵ���elem���Ԫ�أ�����ǰbreak
        //��ʱ��ִ��һ��i++
        //i�պ�Ҳ������ȷ����λ��
        if(p->data>=elem)
            break;
        i++;
    }
    ListInsert(head,i,elem);
    return i;
}









