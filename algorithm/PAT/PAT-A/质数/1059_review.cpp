#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[50000] = {0};
vector<int> prime;
int main()
{
    vis[0] = vis[1] = 0;
    for (int i = 2; i < 50000; i++)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            for (int j = 2 * i; j < 50000; j += i)
                vis[j] = 1;
        }
    }
    // for (int i = 0; i < prime.size();i++)
    //     cout << prime[i] << " ";
    long long n;
    cin >> n;
    if (n == 1)
        cout << n << "=1\n";
    else
    {
        int fir = 1;
        cout << n << "=";
        for (int i = 0;; i++)
        {
            if (n == 1)
                break;
            if (n % prime[i] != 0)
                continue;
            if(!fir)
                cout << "*";
            cout << prime[i];
            int cnt = 0;
            while (n % prime[i] == 0)
            {
                cnt++;
                n /= prime[i];
            }
            if (cnt > 1)
                cout << "^" << cnt;
            if(fir)
                fir = 0;
        }
    }

    return 0;
}