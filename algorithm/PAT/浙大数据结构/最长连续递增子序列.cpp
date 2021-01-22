#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct  node
{
    int data;
    int cnt;
    node() { cnt = 1; }
};

int main()
{
    int n;
    cin >> n;
    vector<node>v (n);
    for (int i = 0; i < n;i++)
    {
        cin >> v[i].data;
    }
    for (int i = 0; i < n;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            if(v[j].data>v[j-1].data)
                v[i].cnt++;
            else
            {
                break;
            }
            
        }
    }
    int index, count = -1;
    for (int i = 0; i < n;i++)
    {
        if (v[i].cnt > count)
        {
            count = v[i].cnt;
            index = i;
        }
    }
    cout << v[index].data;
    for (int i = index + 1; i < index + count; i++)
        cout << " " << v[i].data;
    return 0;
}