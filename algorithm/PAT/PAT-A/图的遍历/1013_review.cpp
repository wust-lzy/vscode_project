#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int e[1005][1005];
int vis[1005];
void dfs(int index)
{
    vis[index] = 1;
    for (int i = 1; i <= n;i++)
    if(!vis[i]&&e[index][i])
        dfs(i);
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    while(k--)
    {
        int t;
        cin >> t;
        memset(vis, 0, sizeof(vis));
        vis[t] = 1;
        int cnt = 0;
        for (int i = 1; i <= n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
        return 0;
}
