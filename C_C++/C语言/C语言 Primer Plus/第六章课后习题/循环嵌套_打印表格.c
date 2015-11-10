#include <stdio.h>

int main(void)
{
    int i, n, m;

    scanf("%d %d", &n, &m);
    for (i = n; i <= m; i++)
        printf("i = %-4d i * i = %-4d i * i * i = %-4d\n", i, i * i, i * i * i);

    return 0;
}
