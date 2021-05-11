#include "SeqStack_Alg.h"


void ExpIsCorrect(char *exp,int len)
{
    Stack s;
    SeqStack ss=&s;
    StackInitiate(ss);
    int i,IsOver;//��־---��⵱ջ��ʱ���ַ����Ƿ����������

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
                printf("��Դ�����ȷ��\n");
                return;
            }

            if(StackNotEmpty(ss))//ջ�ǿգ���⵽������
                IsOver=0;//δȷ��
            else if(i<len-1)//ջ�գ���⵽������ && ��������Ϊ���һ������ʱ����⣬��ʱջ�յ��Ƿ���ƥ��
                IsOver=1;//ȷ����������
        }
    }

    if(StackNotEmpty(ss))//�ǿգ���������
    {
        printf("������>������\n");
        return;
    }

    else if(IsOver==1)
    {
        printf("������>������\n");
        return;
    }

    else
    {
        printf("����ƥ��\n");
        return;
    }
}
