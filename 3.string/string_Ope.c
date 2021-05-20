#include "string_Ope.h"
#include <string.h>

//初始化
void Initiate(Dstring *str)
{
    str->len=0;
    str->max_len=0;
    str->String=NULL;
}

//字符串赋值
void Assign_Operate(Dstring *str,const char *src)
{
    int len=strlen(src);
    if(len<=str->max_len&&str->max_len!=0&&str->String!=NULL)
    {
        memcpy(str->String,src,len);
        str->len=len;
        return;
    }

    if(len==0&&str->String==NULL)
    {
        str->String=(char*)malloc(1);
        str->len=0;
        str->max_len=1;
        return;
    }

    //三种状态
    //1、String原为空指针---realloc()申请新空间并赋值给String
    //2、String不为空，realloc()后返回值为原地址---赋给String
    //3、String不为空，realloc()后返回值为新地址---realloc释放老空间，并将新指针赋给String
    char *new_ptr=(char*)realloc(str->String,len);
    str->String=new_ptr;
    memcpy(str->String,src,len);
    str->len=len;
    str->max_len=len;
}

//打印string
void print(const Dstring *str)
{
    if(str->String==NULL)
    {
        printf("please assign!!\n");
        return;
    }

    int i;
    for(i=0;i<str->len;i++)
        printf("%c",str->String[i]);
    printf("\n");
}
