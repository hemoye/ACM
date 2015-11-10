#include <stdio.h>

int main(void)
{
    int sum, temp, t, n, i, j, a[1000];

    scanf("%d", &sum);

    for (t = 1; t <= sum; t++)
    {
        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                if (a[j] < a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
        printf("Case %d:\n", t);
        printf("%d %d", a[0], a[1]);
    }

    return 0;
}
