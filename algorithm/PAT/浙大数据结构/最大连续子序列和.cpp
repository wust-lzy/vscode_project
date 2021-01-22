#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int k;
    cin >> k;
    ll nowsum = 0, maxsum = 0, t;
    for (int i = 0; i < k;i++)
    {
        cin >> t;
        nowsum += t;
        if(nowsum>maxsum)
            maxsum = nowsum;
        else if(nowsum<0)
            nowsum = 0;
    }
    cout << maxsum;
    return 0;
}