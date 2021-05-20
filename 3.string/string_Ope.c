#include "string_Ope.h"
#include <string.h>

//��ʼ��
void Initiate(Dstring *str)
{
    str->len=0;
    str->max_len=0;
    str->String=NULL;
}

//�ַ�����ֵ
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

    //����״̬
    //1��StringԭΪ��ָ��---realloc()�����¿ռ䲢��ֵ��String
    //2��String��Ϊ�գ�realloc()�󷵻�ֵΪԭ��ַ---����String
    //3��String��Ϊ�գ�realloc()�󷵻�ֵΪ�µ�ַ---realloc�ͷ��Ͽռ䣬������ָ�븳��String
    char *new_ptr=(char*)realloc(str->String,len);
    str->String=new_ptr;
    memcpy(str->String,src,len);
    str->len=len;
    str->max_len=len;
}

//��ӡstring
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
