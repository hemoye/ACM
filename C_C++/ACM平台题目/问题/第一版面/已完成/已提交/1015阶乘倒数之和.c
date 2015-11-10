#include <stdio.h>

float fact(float n);

int main(void)
{
    unsigned n;
    int i;
    float sum = 0;

    scanf("%u", &n);
    for (i = 1; i <= n; i++)
        sum += 1 / fact(i);

    printf("%.4f\n", sum);

    return 0;
}
float fact(float n)
{
    int i;
    float s = 1;

    for (i = 1; i <= n; i++)
        s *= i;

    return s;
}
