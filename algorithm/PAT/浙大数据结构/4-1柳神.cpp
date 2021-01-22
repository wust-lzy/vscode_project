#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, post[35], in[35];
bool flag = 1;
void pre(int root,int start,int end)
{
    if(start>end)
        return;
    int i = start;
    while(i < end && in[i] != post[root])
        i++;
    printf(" %d", post[root]);
    pre(root - (end - i + 1), start, i - 1);
    pre(root - 1, i + 1, end);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> post[i];
    for (int i = 0; i < n;i++)
        cin >> in[i];
    printf("Preorder:");
    pre(n - 1, 0, n - 1);
    return 0;
}