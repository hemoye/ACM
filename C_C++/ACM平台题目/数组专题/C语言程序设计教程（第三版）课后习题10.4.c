#include <stdio.h>

int main(void)
{
    int i, j, m, n;
    int a[1000];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);

    for (i = n - m; i < n; i++)
        printf((n - m == i) ? "%d" : " %d", a[i]);
    for (i = 0; i < n - m; i++)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
