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
void Assign_Operate(Dstring *str, const char *src)
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
    //若长度为0，着内核为-1，访问越界
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
    if ((pos > str->len && str->len != 0) || (str->len == 0 && pos > 1))
    {
        printf("Illegal position");
        return 0;
    }

    if ((str->len + sub_str->len) <= str->max_len)
    {
        String_Offset(str, pos, sub_str->len);
        memcpy(str->String + pos - 1, sub_str->String, sub_str->len);
        str->len = str->len + sub_str->len;
        printf("(str->len + sub_str->len) <= str->max_len\n");
        return 1;
    }

    char *new_ptr = (char*)realloc(str->String, str->len + sub_str->len);
    str->String = new_ptr;
    //先偏移在改变数值（len，max_len）
    String_Offset(str, pos, sub_str->len);
    str->max_len = str->len + sub_str->len;
    str->len = str->len + sub_str->len;
    memcpy(str->String + pos - 1, sub_str->String, sub_str->len);
    printf("Other situations\n");
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
    printf("\tlength=%d\tmaxlength=%d\n\n", str->len, str->max_len);
}


//销毁
void destory(Dstring *str)
{
    free(str->String);
    str = NULL;
}
