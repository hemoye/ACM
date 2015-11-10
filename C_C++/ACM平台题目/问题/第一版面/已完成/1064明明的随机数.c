#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned n, a[100];
    int i, j, t;

    scanf("%u", &n);
    for (i = 0l; i < n; i++)
        scanf("%u", &a[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }

    for (i = 0, t = 0; i < n - t; i++)
        if (a[i] == a[i+1])
        {
            t++;
            for (j = i; j < n - 1; j++)
                a[j] = a[j+1];
            i = 0;
        }

    printf("%d", n - t + 1);
    for (i = 0; i < n - t + 1; i++)
        printf(" %u", a[i]);

    return 0;
}
