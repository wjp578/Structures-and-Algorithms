#include "string_Ope.h"
#include <string.h>

//��ʼ��
void Initiate(Dstring *str)
{
    str->len = 0;
    str->max_len = 0;
    str->String = NULL;
}


//�ַ�����ֵ
void Assign_Operate_by_char(Dstring *str, const char *src)
{
    int len = strlen(src);
    if (len <= str->max_len && str->max_len != 0 && str->String != NULL)
    {
        memcpy(str->String, src, len);
        str->len = len;
        //test
//        printf("len <= str->max_len && str->max_len != 0 && str->String != NULL\n");
        return;
    }

    if (len == 0 && str->String == NULL)
    {
        str->String = (char*)malloc(1);
        str->len = 0;
        str->max_len = 1;
//        printf("len == 0 && str->String == NULL\n");
        return;
    }

    //����״̬
    //1��StringԭΪ��ָ��---realloc()�����¿ռ䲢��ֵ��String
    //2��String��Ϊ�գ�realloc()�󷵻�ֵΪԭ��ַ---����String
    //3��String��Ϊ�գ�realloc()�󷵻�ֵΪ�µ�ַ---realloc�ͷ��Ͽռ䣬������ָ�븳��String
    char *new_ptr = (char*)realloc(str->String, len);
    str->String = new_ptr;
    memcpy(str->String, src, len);
    str->len = len;
    str->max_len = len;
//    printf("Other situations\n");
}


//��posλ�ú��ַ�����offset(�Ӵ�����)��λ��
void String_Offset(Dstring *str, int pos, int offset)
{
    int len = str->len, i = 0;
    //���ַ������⡰+1������---�����û����ԣ��ַ���1��ʼ,��Ӧ�ں�0λ��
    //������Ϊ0���޷�����ѭ�����ַ���ƫ�ƴ������������ѭ���������ַ����±�Ϊ-1������Խ��
    if (len == 0)
        len++;
    int count = len - pos + 1; //pos�󣨰���pos��Ԫ�ظ���|��Ҫ�ƶ���Ԫ�ظ���
    for (i = 0; i < count; i++)
    {
        str->String[len - 1 + offset] = str->String[len - 1];
        len--;
    }
}


//�����Ӵ�
//��posλ�ò����Ӵ�
int Insert(Dstring *str, const Dstring *sub_str, int pos)
{
    //posΪ�û�����λ�ã���1��ʼ
    //λ�÷Ƿ����������
    //���ַ���  ��Ϊ  ���ַ���ʱ��λ�ô��ڳ��ȣ�λ�÷Ƿ�
    //���ַ���   Ϊ   ���ַ���ʱ��λ�ô���1��λ�÷Ƿ�
    if ((pos > str->len && str->len != 0) || (str->len == 0 && pos > 1) || pos < 1)
    {
        printf("Illegal position");
        return 0;
    }

    if ((str->len + sub_str->len) <= str->max_len)
    {
        String_Offset(str, pos, sub_str->len);
        memcpy(str->String + pos - 1, sub_str->String, sub_str->len);
        str->len = str->len + sub_str->len;
//        printf("(str->len + sub_str->len) <= str->max_len\n");
        return 1;
    }

    char *tem=sub_str->String;
    char *new_ptr = (char*)realloc(str->String, str->len + sub_str->len);
    str->String = new_ptr;
    //��ƫ���ڸı���ֵ��len��max_len��
    String_Offset(str, pos, sub_str->len);
    str->max_len = str->len + sub_str->len;
    str->len = str->len + sub_str->len;
    memcpy(str->String + pos - 1, tem, sub_str->len);
//    printf("Other situations\n");
    return 1;
}


//ɾ���Ӵ�
//�ڴ�posλ��ɾ��del_len���ֽ�
int Delete(Dstring *str, int pos, int del_len)
{
    if (pos > str->len || pos < 1)
    {
        printf("Illegal position\n");
        return 0;
    }

    if (del_len < 0)
    {
        printf("Illegal delete length\n");
        return 0;
    }

    //����ǰ�pos��ɾ��
    //��ɾ�����ȴ��� pos���ַ�����β�ĳ��ȣ�del_len>=len-pos+1��
    if (del_len >= str->len - pos + 1)
    {
        str->len = pos - 1; //posλ��ҲҪɾ��
//        printf("situation 1\n");
        return 1;
    }

    int i = 0;
    //��pos_del_len-1��--- �ӱ�ɾ��������λ�õ���һ���ַ��ĳ��� --- X
    //len-X --- Ҫ��λ���ַ�����
    for (i = 0; i < str->len - (pos + del_len - 1); i++)
        str->String[pos - 1 + i] = str->String[pos - 1 + i + del_len];
    str->len = str->len - del_len;
//    printf("situation 2\n");
    return 1;
}


//ȡ�Ӵ�
//ȡ��posλ�ÿ�ʼ��get_len���ֽڸ�sub_str
int SubString(Dstring *str, int pos, int get_len,Dstring *sub_str)
{
    if(pos > str->len || pos < 1)
    {
        printf("Illegal position\n");
        return 0;
    }
    else if(get_len<0||pos+get_len-1>str->len)
    {
        printf("Illegal get length\n");
        return 0;
    }

    if(get_len>sub_str->max_len)
    {
        char *new_ptr = (char*)realloc(sub_str->String, get_len);
        sub_str->String = new_ptr;
//        sub_str->len=get_len;
        sub_str->max_len=get_len;
    }
    memcpy(sub_str->String,str->String+pos-1,get_len);
    sub_str->len=get_len;
    return 1;
}


//��ӡstring
void print(const Dstring *str)
{
    if (str->String == NULL)
    {
        printf("please assign!!\n");
        return;
    }

    int i;
    for (i = 0; i < str->len; i++)
        printf("%c", str->String[i]);
    printf("\tlength=%d\tmaxlength=%d\n", str->len, str->max_len);
    printf("\n");
}


//����
void destory(Dstring *str)
{
    free(str->String);
    str = NULL;
}


//�󳤶�
int Length(Dstring *str)
{
    return str->len;
}

//�Ƚϴ�1��2
//����ֵ<0����1С�ڴ�2
//= -1111,��1��2ǰ�ܸ��ַ���ͬ���Ҵ�1���ڴ�2(��1С�ڴ�2)
//����ֵ>0����1���ڴ�2
//= 1111,��1��2ǰ�ܸ��ַ���ͬ���Ҵ�1���ڴ�2
//=0����ͬ
int Campare(const Dstring *str1,const Dstring *str2)
{
    int len=str1->len<str2->len?str1->len:str2->len;
    int i=0;
    for(i=0;i<len;i++)
    {
        if(str1->String[i] != str2->String[i])
            return str1->String[i] - str2->String[i];
    }

    if(str1->len==str2->len)
        return 0;
    else if(str1->len>str2->len)
        return 1111;
    else
        return -1111;
}

//�ַ�����ֵby Dstring
void Assign_Operate_by_Dstring(Dstring *str, const Dstring *src)
{
    Assign_Operate_by_char(str,src->String);
}


//�����Ӵ�
//BF�㷨
//�ҵ��Ӵ�����  ��һ��ƥ���ַ��±�+1  ����ֵ>0
//�մ����κδ�ƥ���ҷ���ֵΪ0
//�Ҳ���ƥ�䴮����-1
int Search_BF(const Dstring *str,int start,const Dstring *sub_str)
{
    if(start>str->len)
    {
        printf("Illegal starting point\n");
        return -1;
    }

    if(sub_str->len>str->len)
    {
        printf("sub_str over long");
        return -1;
    }
    if(sub_str->len==0)
        return 0;

    int cur=start-1,str_s=start-1,subs_s=0;
    int flag=0;
    //��ֹ����
    //���Ӵ�����Ϊ1����ʼλ��Ϊ1
    //�����ж��ҵ�������λ��1
    while(str_s<str->len)
    {
        while(str->String[cur]==sub_str->String[subs_s])
        {
            if(subs_s+1==sub_str->len||cur+1==str->len)
                {
                    flag=1;
                    break;
                }
            cur++;
            subs_s++;
        }

        if(subs_s+1==sub_str->len&&flag==1)
            return str_s+1;

        subs_s=0;
        str_s++;
        cur=str_s;
    }

    return -1;
}
