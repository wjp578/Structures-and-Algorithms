#include <stdio.h>
#include <stdlib.h>
#include "SeqStack_Ope.h"
#include "SeqStack_Alg.h"

int main()
{
    //��������
//    Stack s;
//    SeqStack ss=&s;
//    StackInitiate(ss);
//    int i=0;
//    for(i=0;i<10;i++)
//    {
//        DataType in;
//        scanf("%d",&in);
//        StackPush(ss,in);
//    }
//
//    StackPrint(ss);
//
//    StackPop(ss,NULL);
//    StackPop(ss,NULL);
//    StackPrint(ss);
//
//    StackTop(ss,&i);
//    printf("%d\n",i);



    //�㷨����---����ƥ������
    char *ch1="UVV{{(u[[by]]u)}}";//ƥ��
    char ch2[]="(({da{}f{(da)}aqfsfa}()){rqwfaf[][]af({})})";//ƥ��
    char *ch3="(({qw{}dadqqwf[[]][]}fas{}))(((";//���
    char *ch4="{{12rw;{((d()da[])afqwr)}}}]]]]";//�Ҷ�
    char *ch5="(){g}[af()qwfsa{}]{[aqwrfa}{]}";//����ƥ��

    char *p[5]={ch1,ch2,ch3,ch4,ch5};
    int i=0;
    for(i=0;i<5;i++)
    {
        ExpIsCorrect(p[i],strlen(p[i]));
    }


    return 0;
}
