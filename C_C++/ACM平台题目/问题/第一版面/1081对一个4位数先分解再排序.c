#include <stdio.h>

int main(void)
{
    int sum, i, j, z = 0;
    int a[10];

    scanf("%d", &sum);
    while (sum)
    {
        a[z++] = sum % 10;
        sum /= 10;
    }
    for (i = 0; i < z - 2; i++)
        for (j = 0; j < z - 2 - i; j++)
            if (a[j] > a[j+1])
            {
                sum = a[j];
                a[j] = a[j+1];
                a[j+1] = sum;
            }
    for (i = 0; i < z; i++)
        printf((i < z - 1) ? "%d " : "%d\n", a[i]);

    return 0;
}
