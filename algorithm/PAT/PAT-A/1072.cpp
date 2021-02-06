#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, ds, station;
int e[1020][1020], dis[1020];
bool vis[1020];
const int inf = 1e8;
int main()
{
    fill(e[0], e[0] + 1020 * 1020, inf);
    for (int i = 0; i < 1020; i++)
    {
        e[i][i] = 0;
    }
    fill(dis, dis + 1020, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    string s, t;
    for (int i = 0; i < k; i++)
    {
        int tempdis;
        cin >> s >> t >> tempdis;
        int a, b;
        if (s[0] == 'G')
        {
            a = n + stoi(s.substr(1)); //去掉G字母后面的数字
        }
        else
        {
            a = stoi(s);
        }
        if (t[0] == 'G')
        {
            b = n + stoi(t.substr(1)); //去掉G字母后面的数字
        }
        else
        {
            b = stoi(t);
        }
        e[a][b] = e[b][a] = min(e[a][b], tempdis); //两点之间有多条路 选最短的一条
    }
    int ansid = -1;
    double ansdis = -1, ansaver = inf;
    for (int index = n + 1; index <= n + m; index++)
    {
        double mindis = inf, aver = 0;
        fill(dis, dis + 1020, inf);
        fill(vis, vis + 1020, false);
        dis[index] = 0;
        for (int i = 0; i < n + m; i++)
        {
            int u = -1, minn = inf;
            for (int j = 1; j <= n + m; j++)
            {
                if (!vis[j] && dis[j] < minn)
                {
                    u = j;
                    minn = dis[j];
                }
            }
            if (u == -1)
            {
                break;
            }
            vis[u] = 1;
            for (int v = 1; v <= n + m; v++)
            {
                if (!vis[v] && dis[v] > dis[u] + e[u][v])
                {
                    dis[v] = dis[u] + e[u][v];
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] > ds)
            {
                mindis - 1;
                break;
            }
            if (dis[i] < mindis)
                mindis = dis[i];
            aver += 1.0 * dis[i];
        }
        if (mindis == -1)
            continue;
        aver = aver / n;
        if (mindis > ansdis)
        {
            ansdis = mindis;
            ansid = index;
            ansaver = aver;
        }
        else if (mindis == ansdis && aver < ansaver)
        {
            ansid = index;
            ansaver = aver;
        }
    }

    if (ansid == -1)
    {
        cout << "No Solution";
    }
    else
    {
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansaver);
    }

    return 0;
}