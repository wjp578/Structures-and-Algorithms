#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *String;
    int len;
    int max_len;
} Dstring;

//初始化
void Initiate(Dstring *str);
//字符串赋值
void Assign_Operate(Dstring *str, const char *src);
//打印string
void print(const Dstring *str);
