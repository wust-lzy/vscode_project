#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ori[105], part[105];
void downjust(int low,int high)
{
    int i = low, j = 2 * i;
    while(j<=high)
    {
        if(j+1<=high&&part[j+1]>part[j])
            j++;
        if(part[j]>part[i])
        {
            swap(part[i], part[j]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> ori[i];
    for (int i = 1; i <= n; i++)
        cin >> part[i];
    int index = 1;
    while(index<=n-1&&part[index]<=part[index+1])
        index++;
    int j = index+1;
    while(j<=n&&part[j]==ori[j])
        j++;
    if(j==n+1)
    {
        printf("Insertion Sort\n");
        sort(part+1, part + index + 2);
    }
    else
    {
        printf("Heap Sort\n");
        int pos = n;
        while(pos>2&&part[pos]>=part[1])
            pos--;
        swap(part[1], part[pos]);
        downjust(1, pos - 1);
    }
    for (int i = 1; i <= n;i++)
        {
            cout << part[i];
            if(i!=n)
                cout << " ";
        }
    return 0;
}