#include<bits/stdc++.h>
using namespace std;
int father[1010],isroot[1010]={0};
int vis[1010] = {0};
int findfather(int x)
{
    if(x==father[x])
        return x;
    int f = findfather(father[x]);
    father[x] = f;
    return f;
}
void Union(int a,int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb)
        father[fa] = fb;
}
void init(int n)
{
    for (int i = 1; i <= n;i++)
        father[i] = i;
}
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int n, k;
    cin >> n;
    init(n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d:", &k);
        for (int j = 0; j < k;j++)
        {
            int temp;
            scanf("%d", &temp);
            if(!vis[temp])
                vis[temp] = i;
            Union(i, vis[temp]);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n;i++)
        isroot[findfather(i)]++;
    for (int i = 1; i <= n;i++)
    if(isroot[i])
        cnt++;
    cout << cnt << endl;
    sort(isroot + 1, isroot + 1 + n, cmp);
    for (int i = 1; i <= cnt;i++)
    {
        cout << isroot[i];
        if(i!=cnt)
            cout << " ";
    }
        return 0;
}
