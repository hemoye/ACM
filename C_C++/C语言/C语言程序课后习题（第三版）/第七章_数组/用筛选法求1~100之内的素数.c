#include <stdio.h>
int main(void)
{
    int i, j;

    for (i = 2; i < 100; i++)
    {
        for (j = 2; j <= i; j++)
            if (0 == i % j)
                break;
        if (i == j)
            printf("%d\n", i);
    }
}
