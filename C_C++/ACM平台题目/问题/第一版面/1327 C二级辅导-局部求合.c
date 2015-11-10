#include <stdio.h>

int main(void)
{
    int a[20];
    int i, j;

    for (i = 0; i < 20; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < 20; i++)
        for (j = 0; j < 20; j++)
        {
            if (j == i)
                continue;
            if (0 == a[i] % a[j])
            {
                printf("%d\n", a[i]);
                break;
            }
        }

    return 0;
}
