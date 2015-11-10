#include <stdio.h>

int main(void)
{
    long t, n, i, z, a[100] = {1, 1, 1};

    scanf("%d", &t);
    for (z = 1; z <= t; z++)
    {
        scanf("%d", &n);

        printf("Case %d: ", z);
        for (i = 3; i < n; i++)
            a[i] = (2 * a[i-3] + a[i-1]) % 1000000;
        printf("%ld\n", a[n - 1]);
    }

    return 0;
}
