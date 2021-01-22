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
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

List Insert( List L, ElementType X )
{
    List p = L;
    int i = 0;
    while(p->Next!=NULL)
    {
        if(p->Next->Data>X)
            break;
        else
        {
            p = p->Next;
        }
    }
    List temp = (List)malloc(sizeof(struct Node));
    temp->Next = p->Next;
    temp->Data = X;
    p->Next = temp;
    return L;
}