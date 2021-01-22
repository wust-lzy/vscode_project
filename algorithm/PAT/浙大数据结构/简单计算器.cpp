#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll sum = 0;
    char c;
    cin >> sum >> c;
    while(c!='=')
    {
        if(c=='+')
        {
            int t;
            cin >> t;
            sum = sum + t;
        }
        else if(c=='-')
        {
            int t;
            cin >> t;
            sum = sum - t;
        }
        else if(c=='*')
        {
            int t;
            cin >> t;
            sum = sum * t;
        }
        else if(c=='/')
        {
            int t;
            cin >> t;
            if(!t)
            {
                cout << "ERROR";
                return 0;
            }
            sum = sum / t;
        }
        else
        {
            cout << "ERROR";
                return 0;
        }
        cin >> c;
    }
    cout << sum;
    return 0;
}