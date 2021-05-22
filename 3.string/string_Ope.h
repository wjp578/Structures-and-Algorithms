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
//�ַ�����ֵby char*
void Assign_Operate_by_char(Dstring *str, const char *src);
//�ַ�����ֵby Dstring
void Assign_Operate_by_Dstring(Dstring *str, const Dstring *src);
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
//�󳤶�
int Length(Dstring *str);
//�Ƚϴ�
int Campare(const Dstring *str1,const Dstring *str2);
//�����Ӵ�---BF�㷨
int Search_BF(Dstring *str,int start,Dstring *sub_str);
