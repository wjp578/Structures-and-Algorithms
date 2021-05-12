#include "ChStack_Alg.h"

//打印表达式
void PrintExp(char *str)
{
    int i=0;
    while((*(str+i))!='#')
        printf("%c",*(str+(i++)));
    printf("\n");
}

//比较符号优先级
// > --- 2
// < --- 1
// = --- 0
// 不存在--- -1
int Compare_Priority(char the1_stacktop,char the2_scanstr)
{
    if(the1_stacktop=='+')
    {
        if(the2_scanstr=='+'||the2_scanstr=='-'||the2_scanstr==')'||the2_scanstr=='#')
            return 2;
        else
            return 1;
    }

    if(the1_stacktop=='-')
    {
        if(the2_scanstr=='+'||the2_scanstr=='-'||the2_scanstr==')'||the2_scanstr=='#')
            return 2;
        else
            return 1;
    }

    if(the1_stacktop=='*')
    {
        if(the2_scanstr=='(')
            return 1;
        else
            return 2;
    }

    if(the1_stacktop=='/')
    {
        if(the2_scanstr=='(')
            return 1;
        else
            return 2;
    }

    if(the1_stacktop=='(')
    {
        if(the2_scanstr==')')
            return 0;
        else if(the2_scanstr=='#')
            return -1;
        else
            return 1;
    }

    if(the1_stacktop==')')
    {
        if(the2_scanstr=='(')
            return -1;
        else
            return 2;
    }

    if(the1_stacktop=='#')
    {
        if(the2_scanstr=='#')
            return 0;
        else if(the2_scanstr==')')
            return -1;
        else
            return 1;
    }

    return 32765;
}

//中缀转后缀
void MidTransformLast(char *Mid,char *Last)
{
//    char Last[MAX_LENGTH]={0};
    int mid_pos=0,last_pos=0;

    //初始化
    CStack cs;
    StackInitiate(&cs);
    StackPush(cs,'#');

    //中转后
    char the1,the2;
    while(1)
    {
        the2=*(Mid+mid_pos);

        //测试中转后
        if((the2>='a' && the2<='z') || (the2>='A' && the2<='Z'))
        //测试计算值
//        if(the2>='0' && the2<= '9')
        {
            Last[last_pos]=the2;
            mid_pos++;
            last_pos++;
        }

//        if(the2=='+'||the2=='-'||
//           the2=='*'||the2=='/'||
//           the2=='('||the2==')'||
//           the2=='#')
        //所有符号都能进行比较
        //非法符号有特殊返回值和处理模式---32765
        else
        {
            the1=StackTop(cs);
            int compare=Compare_Priority(the1,the2);

            //特殊情况  the1=the2
            if(compare==0)
            {
                //便利到结束符，结束循环
                if(the1=='#'&&the2=='#')
                {
                    Last[last_pos]=the2;
                    break;
                }

                //消除括号
                if(the1=='('&&the2==')')
                {
                    mid_pos++;
                    StackPop(cs,NULL);
                }
            }



            //表达式逻辑有误或检测到非法字符
            if(compare == -1 || compare == 32765)
            {
                char *seed="Expression input error#";
                int i=0;
                while((*(seed+(i++))) != '\0')
                    Last[i-1]=seed[i-1];
                break;
            }

            //the1<the2
            if(compare==1)
            {
                StackPush(cs,the2);
                mid_pos++;
            }

            //the1>the2
            if(compare==2)
            {
                StackPop(cs,&the1);
                Last[last_pos]=the1;
                last_pos++;
                //出栈后，中缀表达式仍在原位，继续对比该符号与栈顶符号的优先级
//                mid_pos++;
            }
        }
    }

    //销毁栈
    StackDestory(cs);
    cs=NULL;

//    return Last;
}
