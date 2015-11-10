#include <stdio.h>
#include <math.h>

int main(void)
{
    int a[10000], b[10000];
    int i, j, m, n, ga = 999;

    scanf("%d", &m);
    scanf("%d", &n);

    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    for (j = 0; j < n; j++)
        scanf("%d", &b[j]);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (ga > fabs(a[i] - b[j]))
                ga = fabs(a[i] - b[j]);
    printf("%d\n", ga);

    return 0;
}
