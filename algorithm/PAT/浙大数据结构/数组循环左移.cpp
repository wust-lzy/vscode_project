#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a, n, i;
    cin >> a >> n;
    if(!n)
    {
        cout << 0;
        return 0;
    }
    vector<int> v(n+5);
    ll remain = 0;
    for (i = 0; i < n;i++)
    {
        ll tempsum = a * (n - i) + remain;
        v[i] = tempsum % 10;
        remain = tempsum / 10;
    }
    if(remain)
        v[i] = remain;
    else
    {
        i--;
    }
    
    for (; i >= 0;i--)
        cout << v[i];
    return 0;
}