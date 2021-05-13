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
//        if((the2>='a' && the2<='z') || (the2>='A' && the2<='Z'))
        //���Լ���ֵ
        if(the2>='0' && the2<= '9')
        {
            Last[last_pos]=the2;
            mid_pos++;
            last_pos++;

            //�ӵ�'.'�ָ�����
            if((*(Mid+mid_pos))<'0' || (*(Mid+mid_pos))>'9')
            {
                Last[last_pos]='.';
                last_pos++;
            }
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

//�ַ���ת��ֵ
//����ת���������
int str2num(char *str)
{
    int count=0;
    int ret;
    char *c=str;
    while(*c!='.')
    {
        count++;
        c++;
    }
    int i=0;
    for(i=0;i<=count;i++)
    {
        if(i==0)
            ret+=str[i];
        else
        {
            ret*=10;
            ret+=str[i];
        }
    }

    return ret;

}

//����ת�ַ���
//�������ֳ���
int num2str(int num,char *str)
{
    int cpynum=num;
    int count=0;
    while(cpynum)
    {
        cpynum/=10;
        count++;
    }

    int i=1;
    for(i=1;i<=count;i++)
    {
        int rem=num%10;
        num/=10;
        str[count-i]=(char)(rem+'0');
    }
    str[count]='.';
    return count;
}


int EvaluatingPostfixExpressions(char *Last)
{
    CStack cs_num;
//    CStack cs_sym;
    StackInitiate(&cs_num);
//    StackInitiate(&cs_sym);
    StackPush(cs_num,'#');
//    StackPush(cs_sym,'#');

    char n2s[6]={0};
    char s2n[6]={0};

    char ch;
    while((ch=(*(Last++))!='#'))
    {
        if((ch>'0' && ch<'9') || ch=='.')
            StackPush(cs_num,ch);

        if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            int i=0;
            int num1,num2;
            char tem;

            //num2
            StackPop(cs_num,&tem);
            s2n[i]=tem;
            i++;

            while(StackTop(cs_num)!='.')
            {
                StackPop(cs_num,&tem);
                s2n[i]=tem;
                i++;
            }

            int left=0,right=i-1;
            while(left<right)
            {
                char t=s2n[left];
                s2n[left]=s2n[right];
                s2n[right]=t;
                left++;
                right--;
            }

            num2=str2num(s2n);


            //num1
            i=0;
            StackPop(cs_num,&tem);
            s2n[i]=tem;
            i++;

            while(StackTop(cs_num)!='.')
            {
                StackPop(cs_num,&tem);
                s2n[i]=tem;
                i++;
            }

            left=0;
            right=i-1;
            while(left<right)
            {
                char t=s2n[left];
                s2n[left]=s2n[right];
                s2n[right]=t;
                left++;
                right--;
            }

            num1=str2num(s2n);

            if(ch=='+')
                num1+=num2;
            if(ch=='-')
                num1-=num2;
            if(ch=='*')
                num1*=num2;
            if(ch=='/')
                num1/=num2;

            int len=num2str(num1,n2s);
            for(i=0;i<len+1;i++)
            {
                StackPush(cs_num,n2s[i]);
            }
        }
    }

    //�������ֵ
    int i=0;
    int num;
    char tem;

    StackPop(cs_num,&tem);
    s2n[i]=tem;
    i++;

    while(StackTop(cs_num)!='#')
    {
        StackPop(cs_num,&tem);
        s2n[i]=tem;
        i++;
    }

    int left=0,right=i-1;
    while(left<right)
    {
        char t=s2n[left];
        s2n[left]=s2n[right];
        s2n[right]=t;
        left++;
        right--;
    }

    num=str2num(s2n);

    return num;

}
