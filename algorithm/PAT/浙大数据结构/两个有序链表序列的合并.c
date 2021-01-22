#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge( List L1, List L2 )
{
    List p, L, p1, p2;
    p1 = L1->Next;
    p2 = L2->Next;
    L = (List)malloc(sizeof(List));
    // L->Data = L1->Data + L2->Data;
    p = L;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->Data<p2->Data)
        {
            p->Next = p1;
            p = p->Next;
            p1 = p1->Next;
        }
        else
        {
            p->Next = p2;
            p = p->Next;
            p2 = p2->Next;
        }
    }
    if(p1!=NULL)
        p->Next = p1;
    else if(p2!=NULL)
        p->Next = p2;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}