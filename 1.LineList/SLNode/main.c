#include <stdio.h>
#include <stdlib.h>
#include "SLNode_Ope.h"

int main()
{
    SNodeList sln=NULL;

    ListInitiate(&sln);
    printf("%d\n",ListLength(sln));
    ListDestory(sln);

    return 0;
}
