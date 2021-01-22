#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i*i<=n;i++)
    if(n%i==0)
        return 0;
    return 1;
}
int main()
{
    int n,d;
    while(cin>>n)
    {
        if(n<0)
            return 0;
        cin >> d;
        if(!isprime(n))
            cout << "No" << endl;
        else
        {
            int num[100], cnt = 0;
            while (n)
            {
                num[cnt++] = n % d;
                n /= d;
            } 
            for (int i = 0; i < cnt;i++)
                n = n * d + num[i];
            if(isprime(n))
                cout << "Yes" << endl;
            else
            {
                cout << "No" << endl;
            }
            
        }
        
    }
    return 0;
}