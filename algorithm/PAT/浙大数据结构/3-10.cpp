#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void move(char a, char b)
{
    // cout << a << " -> " << b << endl;
    printf("%c -> %c\n", a, b);
}
void hanoi(ll n, char x, char y, char z)
{
    if(n==1)                            //欲移动n个圆盘，需先移动其上的n-1个圆盘
        move(x, z);                  //将编号为1的圆盘从x移到z
    else
    {
        hanoi(n-1, x, z, y);            //将x上编号为1至n-1的圆盘移到y，z作辅助塔
        move(x, z);                  //将编号为n的圆盘从x移到z
        hanoi(n-1, y, x, z);            //将y上编号为1至n-1的圆盘移动到z，x作辅助塔
    }
}
int main()
{
    ll n;
    cin>>n;
    hanoi(n,'a','b','c');
    return 0;
}