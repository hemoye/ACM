#include <stdio.h>
int main(void)
{
    float fact(unsigned n);

    unsigned m, n;
    int a, b, c;

    scanf("%u %u", &m, &n);
    a = fact(m);
    b = fact(n);
    c = fact(m - n);
    a /= (b * c);

    printf("%d\n", a);

    return 0;
}
float fact(unsigned n)
{
    int i;
    float s = 1;

    for (i = 1; i <= n; i++)
        s *= i;

    return s;
}
