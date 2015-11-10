#include <stdio.h>
#include <math.h>

int main(void)
{
    int t, n, i, j, sum, temp, a[1000];

    scanf("%d", &sum);

    for (t = 1; t <= sum; t++)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i- 1; j++)
                if (fabs(a[j]) < fabs(a[j+1]))
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
        printf("Case %d:\n", t);
        for (i = 0; i < n; i++)
            printf((0 == i) ? "%d" : " %d", a[i]);
        printf("\n");
    }

    return 0;
}
