#include <stdio.h>
#include <stdlib.h>
#include "ChStack_Ope.h"
#include "ChStack_Alg.h"
#include <time.h>

////��������
//int main()
//{
//    CStack cs;
//    StackInitiate(&cs);
//
//    srand((unsigned int)time(NULL));
//    int i=0;
//    for(;i<25;i++)
//        StackPush(cs,rand()%10);
//    StackPrint(cs);
//
//    //��ջ
//    int popval;
//    for(i=0;i<10;i++)
//    {
//        StackPop(cs,&popval);
//        printf("pop %d\n",popval);
//    }
//    StackPrint(cs);
//
//    //ȡջ��
//    printf("%d\n",StackTop(cs));
//    //����ջ�ǿգ�����ָ��Ϊ��
//    StackPop(cs,NULL);
//    StackPrint(cs);
//
//    //����ջ��
//    for(i=0;i<20;i++)
//    {
//        StackPop(cs,NULL);
////        printf("pop %d",popval);
//    }
//    StackPrint(cs);
//
//    StackDestory(cs);
//    return 0;
//}


//�㷨����
int main()
{
//    char* str="A+(B-(a*v+g+r)/(r+C)/D)*E#";
//    char* str="12+(13+33/3)*43#";
//    char *str="2+13#";

    char str[MAX_LENGTH]={0};
    char ret[MAX_LENGTH]={0};
    printf("��������ʽ(0~32767����'#'��������):");
    scanf("%s",str);
    MidTransformLast(str,ret);
    PrintExp(ret);

    int res=EvaluatingPostfixExpressions(ret);
    printf("result=%d\n",res);




//    char ch[1000]="�������";
////    ch="�������";
//    printf("%s",ch);
    return 0;
}
