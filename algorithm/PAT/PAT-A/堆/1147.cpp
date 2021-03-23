#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node
{
    int val, left = -1, right = -1;
};
void post(vector<int>&v,int index)
{
    if(index>n)
        return;
    post(v, 2 * index);
    post(v, 2 * index + 1);
    printf("%d%s", v[index],index==1?"\n":" ");
}
int main()
{
    int t;
    cin >> t >> n;
    while(t--)
    {
        int maxn = 1, minn = 1;//大顶堆和小顶堆
        vector<int> level(n + 1);
        for (int i = 1; i <= n;i++)
            cin >> level[i];
        for (int i = 2; i <= n;i++)
        {
            if(level[i]>level[i/2])//子节点大于父节点
                maxn = 0;
            if(level[i]<level[i/2])//子节点小于父节点
                minn = 0;
        }
        if(maxn)
            cout << "Max Heap\n";
        else if(minn)
            cout << "Min Heap\n";
        else
            cout << "Not Heap\n";
        post(level,1);
    }
     
    return 0;
}