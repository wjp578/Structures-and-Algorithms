#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *String;
    int len;
    int max_len;
} Dstring;

//���ַ����ڴ˴�Ҫע��
//��������Կ��ַ��������⴦��

//��ʼ��
void Initiate(Dstring *str);
//��posλ�ú��ַ�����offset(�Ӵ�����)��λ��
void String_Offset(Dstring *str, int pos, int offset);
//�ַ�����ֵ
void Assign_Operate(Dstring *str, const char *src);
//��ӡstring
void print(const Dstring *str);
//����
void destory(Dstring *str);
//�����Ӵ�
int Insert(Dstring *str, const Dstring *sub_str, int pos);
//ɾ���Ӵ�
int Delete(Dstring *str, int pos, int del_len);
//ȡ�Ӵ�
int SubString(Dstring *str, int pos, int get_len,Dstring *sub_str);
