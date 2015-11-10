#include <stdio.h>
int main(void)
{
    int m, n, t;

    scanf("%d %d", &m, &n);
    if (n > m)
    {
        t = n;
        n = m;
        m = t;
    }

    while (m % n)
    {
        t = m % n;
        m = n;
        n = t;
    }
    printf("%d\n", n);
}
