#include <stdio.h>
#include <stdlib.h>
#include "string_Ope.h"

int main()
{
    Dstring str1,str2;
    Dstring *string1=&str1,*string2=&str2;
    Initiate(string1);
    Initiate(string2);

    //��ֵ�����������
//    Assign_Operate(string1,"");
//    print(string1);

    Assign_Operate_by_char(string1,"abaiasbd");
    print(string1);

//    Assign_Operate_by_char(string1,"nnmm");
//    print(string1);

    Assign_Operate_by_char(string2,"ads");
    print(string2);

    //�������

//    Insert(string1,string2,1);
//    print(string1);
    Insert(string2,string2,2);
    print(string2);

    //ɾ������
    Delete(string1,1,0);
//    print(string1);

    //ȡ�Ӵ�����
//    print(string2);
    SubString(string1,2,5,string2);
//    print(string2);

    //�Ƚϲ���
    print(string1);
    print(string2);
    printf("%d\n",Campare(string1,string2));

    //����
    //BF
//    Delete(string2,1,2);
    print(string1);
    print(string2);
    printf("%d\n",Search_BF(string1,1,string2));


    destory(string1);
    destory(string2);

    return 0;
}
