#include "SeqStack_Ope.h"

//栈底为 1
//栈顶为 MAX_SIZE
//栈初始化
void StackInitiate(SeqStack ss)
{
    ss->top=0;
}

//判断非空
//非空---1
//空---0
int StackNotEmpty(const SeqStack ss)
{
    if(ss->top<=0)
        return 0;
    return 1;
}

//入栈
//成功---1
//失败---0
int StackPush(SeqStack ss,DataType val)
{
    if(ss->top>=MAX_SIZE)
    {
        printf("Stack overflow,fail to push\n");
        return 0;
    }

    ss->top++;
    ss->Stack[ss->top-1]=val;//数组从0开始计数
    printf("push successfully\n");
    return 1;
}

//出栈
//第二个元素返回 删除值
//成功---1
//失败---0
int StackPop(SeqStack ss,DataType *ret)
{
    if(!StackNotEmpty(ss))//栈空
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

//取栈顶元素
//第二个元素返回 取得值
//成功---1
//失败---0
int StackTop(const SeqStack ss,DataType *ret)
{
    if(!StackNotEmpty(ss))//栈空
    {
        printf("Stack is empty,fail to get\n");
        return 0;
    }

    if(ret)
        *ret=ss->Stack[ss->top-1];
    printf("get successfully\n");
    return 1;
}

//打印栈元素
void StackPrint(const SeqStack ss)
{
    int i=0;
    for(i=0;i<ss->top;i++)
        printf("%d ",ss->Stack[i]);
    printf("\n");
}
