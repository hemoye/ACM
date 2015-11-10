#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, t, k, i, sum, a[1000][2];
    char str[100][1001];

    scanf("%d", &n);
    for (t = 1; t <= n; t++)
    {
        sum = 0;

        scanf("%d", &k);
        for (i = 0; i < k; i++)
        {
            scanf("%s %d %d", str[i], &a[i][0], &a[i][1]);
            sum += a[i][0] * a[i][1];
        }

        printf("Case %d:\n%d\n", t, sum);
    }

    return 0;
}
