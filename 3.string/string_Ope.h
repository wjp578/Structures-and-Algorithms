#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *String;
    int len;
    int max_len;
} Dstring;

//��ʼ��
void Initiate(Dstring *str);
//�ַ�����ֵ
void Assign_Operate(Dstring *str, const char *src);
//��ӡstring
void print(const Dstring *str);
