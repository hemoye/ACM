#include <stdio.h>

int isprime(int x);

int main(void)
{
    unsigned m, n;
    int i, sum = 0;

    scanf("%d %d", &m, &n);
    for (i = m; i <= n; i++)
        sum += isprime(i);

    printf("%d\n", sum);

    return 0;
}
int isprime(int x)
{
    int i;

    for (i = 2; i <= x; i++)
        if (0 == x % i)
            break;
    if (x == i)
        return x;
    else
        return 0;

}
