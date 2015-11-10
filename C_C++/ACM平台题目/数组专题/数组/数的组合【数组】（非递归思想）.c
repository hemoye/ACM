#include <stdio.h>

int main(void)
{
    int i, j, x, mark;
    int a[6];

    for (i = 0; i < 6; i++)
        scanf("%d", &a[i]);
    scanf("%d", &mark);
    for (i = 5; i >= 3; i--)
    {
        for (x = i; x >= 3; x--)
        {
            printf("%d", a[i]);
            for (j = x - 1; j >= x - 3; j--)
                printf("%d", a[j]);
            if (i < 6)
                printf(",");
        }
    }

    return 0;
}
