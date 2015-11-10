#include <stdio.h>
int main(void)
{
    int m, n, t, x, y;

    scanf("%d %d", &m, &n);
    y = m * n;
    if (m > n)
    {
        t = m;
        m = n;
        n = t;
    }
    while (m % n)
    {
        x = m % n;
        m = n;
        n = x;
    }
    printf("%d %d\n", n, y / n);
}
