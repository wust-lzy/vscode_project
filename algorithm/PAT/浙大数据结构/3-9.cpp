#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t, m;
    cin >> t >> m;
    cin.ignore();
    while (t--)
    {
        stack<int> s;
        string str;
        getline(cin, str);
        bool flag = 1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'S')
            {
                s.push(1);
                if(s.size()>m)//S满栈
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                if(s.empty())//X空栈
                {
                    flag = 0;
                    break;
                }
                s.pop();
            }  
        }
        if(!s.empty()) //结束时非空
        {
            flag = 0;
        }
        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}