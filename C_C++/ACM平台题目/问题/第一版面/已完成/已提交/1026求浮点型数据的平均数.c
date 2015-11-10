#include <stdio.h>
int main(void)
{
    int n, i;
    float sum = 0, a[100] = {0};

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
        sum += a[i];
    }
    sum /= n;

    printf("%.2f\n", sum);

    return 0;
}
