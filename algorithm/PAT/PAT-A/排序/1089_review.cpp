#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ori[105], part[105];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ori[i];
    for (int i = 1; i <= n; i++)
        cin >> part[i];
    int index = 1;
    while (index <= n - 1 && part[index] <= part[index + 1])
        index++;
    int j = index + 1;
    while (j <= n && part[j] == ori[j])
        j++;
    if (j == n + 1)
    {
        printf("Insertion Sort\n");
        sort(ori + 1, ori + index + 2);
    }
    else
    {
        printf("Merge Sort\n");
        bool flag = 1;
        int k = 1;
        while (flag)
        {
            flag = 0;
            for (int i = 1; i <= n; i++)
                if (ori[i] != part[i])
                {
                    flag = 1;
                    break;
                }
            k *= 2;
            for (int i = 0; i < n / k; i++)
                sort(ori + 1 + i * k, ori + 1 + (i + 1) * k);
            sort(ori + 1 + (n / k) * k, ori + n+1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ori[i];
        if (i != n)
            cout << " ";
    }
    return 0;
}