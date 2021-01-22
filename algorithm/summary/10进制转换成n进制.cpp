#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt = 0;
void tentox(int n,int d) //10进制转换成d进制，保存在数组
{
    int num[100];
    do
    {
        num[cnt++] = n % d;
        n /= d;
    } while (n);
}
void xtoten(int *num,int d)//d进制转换成十进制
{
    int n = 0;
    for (int i = cnt-1; i >=0; i--)
    n = n * d + num[i];
}
int main()
{
    return 0;
}