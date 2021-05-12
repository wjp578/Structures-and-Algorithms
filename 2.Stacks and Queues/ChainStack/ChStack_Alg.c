#include "ChStack_Alg.h"

//��ӡ���ʽ
void PrintExp(char *str)
{
    int i=0;
    while((*(str+i))!='#')
        printf("%c",*(str+(i++)));
    printf("\n");
}

//�ȽϷ������ȼ�
// > --- 2
// < --- 1
// = --- 0
// ������--- -1
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

//��׺ת��׺
void MidTransformLast(char *Mid,char *Last)
{
//    char Last[MAX_LENGTH]={0};
    int mid_pos=0,last_pos=0;

    //��ʼ��
    CStack cs;
    StackInitiate(&cs);
    StackPush(cs,'#');

    //��ת��
    char the1,the2;
    while(1)
    {
        the2=*(Mid+mid_pos);

        //������ת��
        if((the2>='a' && the2<='z') || (the2>='A' && the2<='Z'))
        //���Լ���ֵ
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
        //���з��Ŷ��ܽ��бȽ�
        //�Ƿ����������ⷵ��ֵ�ʹ���ģʽ---32765
        else
        {
            the1=StackTop(cs);
            int compare=Compare_Priority(the1,the2);

            //�������  the1=the2
            if(compare==0)
            {
                //������������������ѭ��
                if(the1=='#'&&the2=='#')
                {
                    Last[last_pos]=the2;
                    break;
                }

                //��������
                if(the1=='('&&the2==')')
                {
                    mid_pos++;
                    StackPop(cs,NULL);
                }
            }



            //���ʽ�߼�������⵽�Ƿ��ַ�
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
                //��ջ����׺���ʽ����ԭλ�������Աȸ÷�����ջ�����ŵ����ȼ�
//                mid_pos++;
            }
        }
    }

    //����ջ
    StackDestory(cs);
    cs=NULL;

//    return Last;
}
