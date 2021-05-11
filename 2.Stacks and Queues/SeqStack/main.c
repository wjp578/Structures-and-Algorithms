#include <stdio.h>
#include <stdlib.h>
#include "SeqStack_Ope.h"
#include "SeqStack_Alg.h"

int main()
{
    //²Ù×÷²âÊÔ
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



    //Ëã·¨²âÊÔ---À¨ºÅÆ¥ÅäÎÊÌâ
    char *ch1="UVV{{(u[[by]]u)}}";//Æ¥Åä
    char ch2[]="(({da{}f{(da)}aqfsfa}()){rqwfaf[][]af({})})";//Æ¥Åä
    char *ch3="(({qw{}dadqqwf[[]][]}fas{}))(((";//×ó¶à
    char *ch4="{{12rw;{((d()da[])afqwr)}}}]]]]";//ÓÒ¶à
    char *ch5="(){g}[af()qwfsa{}]{[aqwrfa}{]}";//´ÎÐò²»Æ¥Åä

    char *p[5]={ch1,ch2,ch3,ch4,ch5};
    int i=0;
    for(i=0;i<5;i++)
    {
        ExpIsCorrect(p[i],strlen(p[i]));
    }


    return 0;
}
