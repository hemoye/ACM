#include <stdio.h>
int main(void)
{
    int N, i, m, n;
    n = 1, m = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        n = (n + 1) * 2;

    printf("%d\n", n / 2 - 1);
}
