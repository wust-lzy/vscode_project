#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v[1005];
int vis[1005]={0};
int n, l;
int bfs(int index)
{
    queue<pair<int, int> > q;
    q.push(pair<int, int>(index,0));
    int cnt = 0;
    vis[index] = 1;
    while(!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for (int i = 0; i < v[temp.first].size();i++)
        {
            int t = v[temp.first][i];
            if(!vis[t]&&(temp.second+1)<=l)
            {
                vis[t] = 1;
                q.push(pair<int, int>(t, temp.second + 1));
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    cin >> n >> l;
    int k;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &k);
        int t;
        for (int j = 0; j < k;j++)
        {
            scanf("%d", &t);
            v[t].push_back(i);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q;i++)
    {
        cin >> k;
        memset(vis, 0, sizeof(vis));
        cout << bfs(k)<<endl;
    }
    return 0;
}