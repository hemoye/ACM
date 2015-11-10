#include <stdio.h>
int main(void)
{
    int startFunction(int n);
    int Cal(int n);

    int n, a, i;
    int sum = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        sum += startFunction(a);
    }

    printf("%d\n", sum);
}
int startFunction(int n)
{
    return Cal(n);
}
int Cal(int n)
{
    int i, sum;
    sum = 0;

    if (0 == n % 2)
        sum += n;

    return sum;
}
