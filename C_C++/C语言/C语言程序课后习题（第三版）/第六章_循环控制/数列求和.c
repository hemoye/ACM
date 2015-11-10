#include <stdio.h>
int main(void)
{
    int a, n, i;
    int s = 0, sum = 0;

    scanf("%d %d", &a, &n);

    for (i = 0; i < n; i++)
    {
        s = s * 10 + a;
        sum += s;
    }
    printf("%d\n", sum);
}
