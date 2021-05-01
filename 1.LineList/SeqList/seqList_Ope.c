#include <stdio.h>
#include <stdlib.h>
#include "seqList_Ope.h"

void ListInitiate(SeqList* sl)
{
    sl->sz=0;
}

int ListLength(const SeqList* sl)
{
    return sl->sz;
}
