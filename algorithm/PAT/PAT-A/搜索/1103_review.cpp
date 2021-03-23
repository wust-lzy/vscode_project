#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, p;
vector<int> fac, ans, temp;
int max_sum = -1;
int quick_pow(int a,int b)//返回a的b次幂
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void init()
{
    int t = 0, index = 0;
    while(t<=n)
    {
        fac.push_back(t);
        index++;
        t = quick_pow(index, p);
    }
}
void dfs(int index,int nowk,int sum,int facsum)
{
    if(nowk==k&&sum==n)
    {
        if(facsum>max_sum)
        {
            max_sum = facsum;
            ans = temp;
        }
        return;
    }
    if(nowk>k||sum>n)
        return;
    if(index>=1)
    {
        temp.push_back(index);//选了
        dfs(index, nowk + 1, sum + fac[index], facsum + index);//继续选
        temp.pop_back();//不选
        dfs(index - 1, nowk, sum, facsum);
    }
}
int main()
{
    cin >> n >> k >> p;
    init();
    dfs(fac.size() - 1, 0, 0, 0);
    if(max_sum==-1)
    {
        cout << "Impossible\n";
        return 0;
    }
    cout << n << " = ";
    for (int i = 0; i < ans.size();i++)
    {
        cout << ans[i] << "^" << p;
        if(i!=ans.size()-1)
            cout << " + ";
    }
        return 0;
}