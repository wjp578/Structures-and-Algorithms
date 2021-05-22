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
//字符串赋值by char*
void Assign_Operate_by_char(Dstring *str, const char *src);
//字符串赋值by Dstring
void Assign_Operate_by_Dstring(Dstring *str, const Dstring *src);
//打印string
void print(const Dstring *str);
//销毁
void destory(Dstring *str);
//插入子串
int Insert(Dstring *str, const Dstring *sub_str, int pos);
//删除子串
int Delete(Dstring *str, int pos, int del_len);
//取子串
int SubString(Dstring *str, int pos, int get_len,Dstring *sub_str);
//求长度
int Length(Dstring *str);
//比较串
int Campare(const Dstring *str1,const Dstring *str2);
//查找子串---BF算法
int Search_BF(Dstring *str,int start,Dstring *sub_str);
