#include <stdio.h>
#include <stdlib.h>
#include "SeqStack_Ope.h"

int main()
{
    Stack s;
    SeqStack ss=&s;
    StackInitiate(ss);
    int i=0;
    for(i=0;i<10;i++)
    {
        DataType in;
        scanf("%d",&in);
        StackPush(ss,in);
    }

    StackPrint(ss);

    StackPop(ss,NULL);
    StackPop(ss,NULL);
    StackPrint(ss);

    StackTop(ss,&i);
    printf("%d\n",i);
    return 0;
}
