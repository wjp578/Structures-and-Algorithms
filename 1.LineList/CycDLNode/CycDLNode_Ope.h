#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;
typedef struct LNode//˫��ѭ������
{
    Datatype val;
    struct LNode* prior;
    struct LNode* next;
}CDLNode,*CycDLNode;

//��ʼ��
void ListInitiate(CycDLNode* head);


