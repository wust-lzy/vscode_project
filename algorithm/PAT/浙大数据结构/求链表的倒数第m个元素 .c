#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}

ElementType Find( List L, int m )
{
    List p = L->Next;
    int len = 0, cnt = 0;
    while(p!=NULL)
    {
        len++;
        p = p->Next;
    }
    if(m>len)
        return ERROR;
    p = L->Next;
    while(cnt<len-m)
    {
        p = p->Next;
        cnt++;
    }
    return p->Data;
}