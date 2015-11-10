#include <stdio.h>
//#include <math.h>

int judge(int );

int main(void)
{
    int i, j, m, n, z;

    scanf("%d%d", &m, &n);
    for (i = m; i <= n; i++)
    {
        int a = 0;
        z = i;
        while (z)
        {
            a = a * 10 + z % 10;
            z /= 10;
        }
        if (a == i && judge(i))
            printf("%d\n", i);
    }

    return 0;
}
int judge(int n)
{
    int i;

    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;

    return 1;
}
