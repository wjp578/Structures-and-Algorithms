#include <stdio.h>
#include <stdlib.h>
#include "string_Ope.h"

int main()
{
    Dstring str1,str2;
    Dstring *string1=&str1,*string2=&str2;
    Initiate(string1);
    Initiate(string2);

    //赋值三种情况测试
//    Assign_Operate(string1,"");
//    print(string1);

    Assign_Operate_by_char(string1,"abdiasbd");
    print(string1);

    Assign_Operate_by_char(string1,"nnmm");
    print(string1);

    //插入测试
    Assign_Operate_by_char(string2,"ads");
    Insert(string1,string2,1);
    print(string1);

    //删除测试
    Delete(string1,1,0);
    print(string1);

    //取子串测试
    print(string2);
    SubString(string1,2,1,string2);
    print(string2);


    destory(string1);
    destory(string2);

    return 0;
}
