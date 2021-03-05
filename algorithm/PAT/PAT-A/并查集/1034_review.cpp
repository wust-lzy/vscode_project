#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<string, int> str_int;
unordered_map<int, string> int_str;
map<string, int> ans;
int cnt = 0;
int g[2020][2020] = {0};
int w[2020] = {0};
int vis[2020] = {0};
int n, k;
int num(string s)
{
    if (!str_int[s])
    {
        str_int[s] = ++cnt;
        int_str[cnt] = s;
        return cnt;
    }
    else
        return str_int[s];
}
int dfs(int now, int &head, int &sum, int &total)
{
    sum++;
    vis[now] = 1;
    if (w[now] > w[head])
        head = now;
    for (int i = 1; i <= cnt; i++)
    {
        if (g[now][i] > 0)
        {
            total += g[now][i];
            g[now][i] = g[i][now] = 0;
            if (!vis[i])
                dfs(i, head, sum, total);
        }
    }
}
void solve()
{
    for (int i = 1; i <= cnt; i++)
    {
        if (!vis[i])
        {
            int head = i, sum = 0, total = 0;
            dfs(i, head, sum, total);
            if (sum > 2 && total > k)
            {
                ans[int_str[head]] = sum;
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        string a, b;
        int v;
        cin >> a >> b >> v;
        int x = num(a);
        int y = num(b);
        w[x] += v;
        w[y] += v;
        g[x][y] += v;
        g[y][x] += v;
    }
    solve();
    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}