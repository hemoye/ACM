#include <stdio.h>

int main(void)
{
    unsigned a[1000];
    unsigned i, j, n, m, temp;

    scanf("%u", &n);
    for (i = 0; i < n; i++)
        scanf("%u", &a[i]);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    for (i = m = 0; i < n - 1; i++)
        if (a[i] == a[i+1])
            m++;
    printf("%u\n%u", 10 - m, a[0]);
    temp = a[0];
    for (i = 1; i < n; i++)
        if (temp != a[i])
        {
            temp = a[i];
            printf(" %u", a[i]);
        }
    puts("");

    return 0;
}
