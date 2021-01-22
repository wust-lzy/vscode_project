#include <stdio.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}

double fn( double x, int n )
{
    if(n==1)
        return x;
    else
    {
        if(n%2==0)
            return -1 * pow(x, n) + fn(x, n - 1);
        else
        {
            return pow(x, n) + fn(x, n - 1);
        }
    }
}