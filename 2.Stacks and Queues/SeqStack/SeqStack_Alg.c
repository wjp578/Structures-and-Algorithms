#include "SeqStack_Alg.h"


void ExpIsCorrect(char *exp,int len)
{
    Stack s;
    SeqStack ss=&s;
    StackInitiate(ss);
    int i,IsOver;//标志---检测当栈空时，字符串是否多余右括号

    for(i=0;i<len;i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            StackPush(ss,exp[i]);

        if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            char tem;
            StackPop(ss,&tem);
            if((exp[i]==')' && tem!='(' && StackNotEmpty(ss)) ||
               (exp[i]==']' && tem!='[' && StackNotEmpty(ss)) ||
               (exp[i]=='}' && tem!='{' && StackNotEmpty(ss)) )
            {
                printf("配对次序不正确！\n");
                return;
            }

            if(StackNotEmpty(ss))//栈非空，检测到右括号
                IsOver=0;//未确定
            else if(i<len-1)//栈空，检测到右括号 && 当右括号为最后一个符号时不检测，此时栈空但是符号匹配
                IsOver=1;//确定多右括号
        }
    }

    if(StackNotEmpty(ss))//非空，多左括号
    {
        printf("左括号>右括号\n");
        return;
    }

    else if(IsOver==1)
    {
        printf("右括号>左括号\n");
        return;
    }

    else
    {
        printf("括号匹配\n");
        return;
    }
}
