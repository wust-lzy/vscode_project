#include <stdio.h>
typedef struct node *polynomial;
struct node
{
    int coef;
    int expon;
    polynomial link;
};
void attach(int c, int e, polynomial *prear)
{
    polynomial p;
    p = (polynomial)malloc(sizeof(struct node));
    p->coef = c;
    p->expon = e;
    p->link = NULL;
    (*prear)->link = p;
    *prear = p;
}
polynomial read()
{
    int n, c, e;
    polynomial p, rear, t;
    scanf("%d", &n);
    p = (polynomial)malloc(sizeof(struct node));
    p->link = NULL;
    rear = p;
    while (n--)
    {
        scanf("%d%d", &c, &e);
        attach(c, e, &rear);
    }
    t = p;
    p = p->link;
    free(t);
    return p;
}
polynomial add(polynomial p1, polynomial p2)
{
    polynomial t1, t2, rear, p, t;
    t1 = p1;
    t2 = p2;
    p = (polynomial)malloc(sizeof(struct node));
    p->link = NULL;
    rear = p;
    while (t1 && t2)
    {
        if (t1->expon == t2->expon)
        {
            int sum = t1->coef + t2->coef;
            if (sum)
                attach(sum, t1->expon, &rear);
            t1 = t1->link;
            t2 = t2->link;
        }
        else if (t1->expon > t2->expon)
        {
            attach(t1->coef, t1->expon, &rear);
            t1 = t1->link;
        }
        else
        {
            attach(t2->coef, t2->expon, &rear);
            t2 = t2->link;
        }
    }
    while (t1)
    {
        attach(t1->coef, t1->expon, &rear);
        t1 = t1->link;
    }
    while (t2)
    {
        attach(t2->coef, t2->expon, &rear);
        t2 = t2->link;
    }
    t = p;
    p = p->link;
    free(t);
    return p;
}

polynomial mul(polynomial p1, polynomial p2)
{
    polynomial t1, t2, rear, p, t;
    int c, e;
    if (!p1 || !p2)
        return NULL;
    t1 = p1;
    t2 = p2;
    p = (polynomial)malloc(sizeof(struct node));
    p->link = NULL;
    rear = p;
    while (t2)
    {
        attach(t1->coef * t2->coef, t1->expon + t2->expon, &rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while (t1)
    {
        t2 = p2;
        rear = p;
        while (t2)
        {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while (rear->link && rear->link->expon > e)
                rear = rear->link;
            if (rear->link && rear->link->expon == e)
            {
                if (rear->link->coef + c)
                    rear->link->coef += c;
                else
                {
                    t = rear->link;
                    rear->link = t->link;
                    free(t);
                }
            }
            else
            {
                t = (polynomial)malloc(sizeof(struct node));
                t->coef = c;
                t->expon = e;
                t->link = rear->link;
                rear->link = t;
                rear = rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }

    t2 = p;
    p = p->link;
    free(t2);
    return p;
}

void printpoly(polynomial p)
{
    int flag = 0;
    if (!p)
    {
        printf("0 0\n");
        return;
    }
    while (p)
    {
        if (!flag)
            flag = 1;
        else
        {
            printf(" ");
        }
        printf("%d %d", p->coef, p->expon);
        p = p->link;
    }
    printf("\n");
}
int main()
{
    polynomial p1, p2, pp, ps;
    p1 = read();
    p2 = read();
    ps = add(p1, p2);
    pp = mul(p1, p2);
    // printpoly(p1);
    // printpoly(p2);
    printpoly(pp);
    printpoly(ps);
    return 0;
}