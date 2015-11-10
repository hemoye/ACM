#include <stdio.h>

float average(int * a, int n)
{
    int i, j, temp, sum = 0;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    for (i = 1; i < n - 1; i++)
        sum += a[i];
    return sum;
}

int main(void)
{
    int i, n;
    int a[1000];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%.2f\n", average(a, n) / (n - 2.0));

    return 0;
}
