#include <stdio.h>

int main(void)
{
    int a[7][2] = {0};
    int i, j, n, max;

    scanf("%d", &n);

    for (i = j = 1; i <= n; i++)
    {
        scanf("%d", &a[i][0]);
        if (a[i][0] == a[i-1][0])
            a[j][1]++;
        else
            j++;
    }
    max = 0;
    for (i = 1; i <= n; i++)
        if (max < a[i][1])
            max = a[i][1];
    printf("%d\n", max+1);

    return 0;
}
