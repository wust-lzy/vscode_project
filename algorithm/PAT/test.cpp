#include <bits/stdc++.h>
using namespace std;
int vis[10];
bool ok[10];
int main()
{
    int vis2[10]={0};
    bool ok2[10];
    cout << "out:";
    for (int i = 0; i < 10; i++)
        cout << vis[i];
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << ok[i];


    cout << endl
         << "in:";
    for (int i = 0; i < 10; i++)
        cout << vis2[i];
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << ok2[i];
    return 0;
}
