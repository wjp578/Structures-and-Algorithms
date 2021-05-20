#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *String;
    int len;
    int max_len;
} Dstring;

//空字符串在此处要注意
//多个函数对空字符串有特殊处理

//初始化
void Initiate(Dstring *str);
//将pos位置后字符后移offset(子串长度)个位置
void String_Offset(Dstring *str, int pos, int offset);
//字符串赋值
void Assign_Operate(Dstring *str, const char *src);
//打印string
void print(const Dstring *str);
//销毁
void destory(Dstring *str);
//插入子串
int Insert(Dstring *str, const Dstring *sub_str, int pos);
