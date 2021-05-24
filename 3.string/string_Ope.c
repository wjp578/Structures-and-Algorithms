#include "string_Ope.h"
#include <string.h>

//初始化
void Initiate(Dstring *str)
{
    str->len = 0;
    str->max_len = 0;
    str->String = NULL;
}


//字符串赋值
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

    //三种状态
    //1、String原为空指针---realloc()申请新空间并赋值给String
    //2、String不为空，realloc()后返回值为原地址---赋给String
    //3、String不为空，realloc()后返回值为新地址---realloc释放老空间，并将新指针赋给String
    char *new_ptr = (char*)realloc(str->String, len);
    str->String = new_ptr;
    memcpy(str->String, src, len);
    str->len = len;
    str->max_len = len;
//    printf("Other situations\n");
}


//将pos位置后字符后移offset(子串长度)个位置
void String_Offset(Dstring *str, int pos, int offset)
{
    int len = str->len, i = 0;
    //空字符串特殊“+1”处理---对于用户而言，字符从1开始,对应内核0位置
    //若长度为0，无法进入循环（字符串偏移处理），假设进入循环，访问字符串下标为-1，访问越界
    if (len == 0)
        len++;
    int count = len - pos + 1; //pos后（包括pos）元素个数|需要移动的元素个数
    for (i = 0; i < count; i++)
    {
        str->String[len - 1 + offset] = str->String[len - 1];
        len--;
    }
}


//插入子串
//在pos位置插入子串
int Insert(Dstring *str, const Dstring *sub_str, int pos)
{
    //pos为用户插入位置，从1开始
    //位置非法的两种情况
    //当字符串  不为  空字符串时，位置大于长度，位置非法
    //当字符串   为   空字符串时，位置大于1，位置非法
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
    //先偏移在改变数值（len，max_len）
    String_Offset(str, pos, sub_str->len);
    str->max_len = str->len + sub_str->len;
    str->len = str->len + sub_str->len;
    memcpy(str->String + pos - 1, tem, sub_str->len);
//    printf("Other situations\n");
    return 1;
}


//删除子串
//在从pos位置删除del_len个字节
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

    //如果是把pos后都删除
    //即删除长度大于 pos到字符串结尾的长度（del_len>=len-pos+1）
    if (del_len >= str->len - pos + 1)
    {
        str->len = pos - 1; //pos位置也要删除
//        printf("situation 1\n");
        return 1;
    }

    int i = 0;
    //（pos_del_len-1）--- 从被删除的最后个位置到第一个字符的长度 --- X
    //len-X --- 要移位的字符个数
    for (i = 0; i < str->len - (pos + del_len - 1); i++)
        str->String[pos - 1 + i] = str->String[pos - 1 + i + del_len];
    str->len = str->len - del_len;
//    printf("situation 2\n");
    return 1;
}


//取子串
//取从pos位置开始的get_len个字节给sub_str
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


//打印string
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


//销毁
void destory(Dstring *str)
{
    free(str->String);
    str = NULL;
}


//求长度
int Length(Dstring *str)
{
    return str->len;
}

//比较串1，2
//返回值<0，串1小于串2
//= -1111,串1、2前能个字符相同，且串1短于串2(串1小于串2)
//返回值>0，串1大于串2
//= 1111,串1、2前能个字符相同，且串1长于串2
//=0，相同
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

//字符串赋值by Dstring
void Assign_Operate_by_Dstring(Dstring *str, const Dstring *src)
{
    Assign_Operate_by_char(str,src->String);
}


//查找子串
//BF算法
//找到子串返回  第一个匹配字符下标+1  返回值>0
//空串和任何串匹配且返回值为0
//找不到匹配串返回-1
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
    //防止误判
    //当子串长度为1，开始位置为1
    //均会判断找到，返回位置1
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
