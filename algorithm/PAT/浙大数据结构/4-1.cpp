#include <bits/stdc++.h>
using namespace std;
int h[35], z[35];
struct node
{
    node *l, *r;
    int data;
};
node *createndoe()
{
    node *p = new node();
    p->l = NULL;
    p->r = NULL;
    return p;
}
void preorder_traver(node *p)
{
    printf(" %d", p->data);
    if (p->l != NULL)
        preorder_traver(p->l);
    if (p->r != NULL)
        preorder_traver(p->r);
}
node *work(int h1, int h2, int z1, int z2)
{
    node *head = createndoe();
    head->data = h[h2];
    for (int i = z1; i <= z2; i++)
    {
        if (z[i] == h[h2])
        {
            if (i != z1)
                head->l = work(h1, h1 + i - z1 - 1, z1, i - 1);
            if (i != z2)
                head->r = work(h2 - z2 + i, h2 - 1, i + 1, z2);
        }
    }
    return head;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> z[i];
    node *head = work(0, n - 1, 0, n - 1);
    printf("Preorder:");
    preorder_traver(head);
    return 0;
}