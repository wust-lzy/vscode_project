#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
const int inf = 1e8;
//点权 ,到i点的点权之和 边权 到i点的最短距离
int weight[210]={0},w[210],e[210][210],dis[210];
int vis[210]={0};
int num[210] = {0};//最短路径的条数
vector<int> pre[210];//记录路径
vector<int> path, temp;
unordered_map<string, int> book;
unordered_map<int, string> result;
string start;
int cnt = 0,max_hap=-1,max_avg=-1;
void dfs(int index)
{
    temp.push_back(index);
    if(index==1)
    {
        int sum = 0;
        for (int i = 0; i < temp.size();i++)
            sum += weight[temp[i]];
        int avg_hap = sum / (temp.size() - 1);
        if(sum>max_hap)
        {
            max_hap = sum;
            max_avg = avg_hap;
            path = temp;
        }
        else if(sum==max_hap&&avg_hap>max_avg)
        {
            max_avg = avg_hap;
            path = temp;
        }
        temp.pop_back();
        return;
    }
    for (int i = 0; i < pre[index].size();i++)
        dfs(pre[index][i]);
    temp.pop_back();
}
int main()
{
    fill(e[0], e[0] + 210 * 210, inf);
    fill(dis, dis + 210, inf);
    string t, a, b;
    cin >> n >> k >> start;
    book[start] = ++cnt;//从1开始
    for (int i = 0; i < n - 1;i++)
    {
        cin >> t;
        book[t] = ++cnt;
        result[cnt] = t;
        scanf("%d", &weight[book[t]]);
    }
    for (int i = 0; i < k;i++)
    {
        cin >> a >> b;
        scanf("%d", &e[book[a]][book[b]]);
        e[book[b]][book[a]] = e[book[a]][book[b]];
    }
    dis[1] = 0;
    num[1] = 1;
    for (int i = 1; i <= n;i++)
    {
        int u = -1, minn = inf;
        for (int j = 1; j <= n;j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if(u==-1)
            break;
        vis[u] = 1;
        for (int v = 1; v <= n;v++){
            if(!vis[v]&&e[u][v]!=inf)
            {
                if(dis[u]+e[u][v]<dis[v])
                {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                    w[v] = w[u] + weight[v];
                }
                else if(dis[u]+e[u][v]==dis[v])
                {
                    num[v] += num[u];
                    pre[v].push_back(u);
                    w[v] = max(w[v], w[u] + weight[v]);
                }
            }
        }
    }
    dfs(book["ROM"]);
    printf("%d %d %d %d\n", num[book["ROM"]], dis[book["ROM"]], max_hap, max_avg);
    cout << start;
    for (int i = path.size() - 2; i >= 0;i--)
        cout << "->" << result[path[i]];
    return 0;
}