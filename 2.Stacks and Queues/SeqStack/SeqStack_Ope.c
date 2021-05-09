#include "SeqStack_Ope.h"

//ջ��Ϊ 1
//ջ��Ϊ MAX_SIZE
//ջ��ʼ��
void StackInitiate(SeqStack ss)
{
    ss->top=0;
}

//�жϷǿ�
//�ǿ�---1
//��---0
int StackNotEmpty(const SeqStack ss)
{
    if(ss->top<=0)
        return 0;
    return 1;
}

//��ջ
//�ɹ�---1
//ʧ��---0
int StackPush(SeqStack ss,DataType val)
{
    if(ss->top>=MAX_SIZE)
    {
        printf("Stack overflow,fail to push\n");
        return 0;
    }

    ss->top++;
    ss->Stack[ss->top-1]=val;//�����0��ʼ����
    printf("push successfully\n");
    return 1;
}

//��ջ
//�ڶ���Ԫ�ط��� ɾ��ֵ
//�ɹ�---1
//ʧ��---0
int StackPop(SeqStack ss,DataType *ret)
{
    if(!StackNotEmpty(ss))//ջ��
    {
        printf("Stack is empty,fail to pop\n");
        return 0;
    }

    if(ret)
        *ret=ss->Stack[ss->top-1];
    ss->top--;
    printf("pop successfully\n");
    return 1;
}

//ȡջ��Ԫ��
//�ڶ���Ԫ�ط��� ȡ��ֵ
//�ɹ�---1
//ʧ��---0
int StackTop(const SeqStack ss,DataType *ret)
{
    if(!StackNotEmpty(ss))//ջ��
    {
        printf("Stack is empty,fail to get\n");
        return 0;
    }

    if(ret)
        *ret=ss->Stack[ss->top-1];
    printf("get successfully\n");
    return 1;
}

//��ӡջԪ��
void StackPrint(const SeqStack ss)
{
    int i=0;
    for(i=0;i<ss->top;i++)
        printf("%d ",ss->Stack[i]);
    printf("\n");
}
