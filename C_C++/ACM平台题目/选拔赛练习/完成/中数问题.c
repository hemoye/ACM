#include <stdio.h>

int main(void)
{
    int i, j, n, t, T, temp, a[1000];

    scanf("%d", &T);

    for (t = 1; t <= T; t++)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i- 1; j++)
                if (a[j] > a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
        printf("Case %d:\n", t);

        if (n % 2 == 1)
           printf("%d\n", a[n/2]);
        else
           printf("%d\n", (a[n/2] + a[(n-1)/2])/2);
    }

    return 0;
}
