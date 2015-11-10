#include <stdio.h>
int main(void)
{
    int a[10];
    int i, num = 0, sum = 0;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sum /= 10;

    for (i = 0; i < 10; i++)
        if (a[i] > sum)
            num++;

    printf("%d\n", sum);

    return 0;
}
