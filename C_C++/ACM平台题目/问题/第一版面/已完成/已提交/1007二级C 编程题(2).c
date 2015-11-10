#include <stdio.h>
int main(void)
{
    double fact(unsigned n);

    unsigned n;
    int i;
    double sum = 0, c = 1;

    scanf("%u", &n);
    for (i = 1; i <= n; i++)
        sum += c / (float)(fact(i));

    printf("sum=%.5lf\n", sum);

    return 0;
}
double fact(unsigned n)
{
    int i;
    double s = 1;

    for (i = 1; i <= n; i++)
        s *= i;

    return s;
}
