#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;
typedef struct LNode//双向循环链表
{
    Datatype val;
    struct LNode* prior;
    struct LNode* next;
}CDLNode,*CycDLNode;

//初始化
void ListInitiate(CycDLNode* head);


