#include <stdio.h>
int main(void)
{
    int i, j;

    for (i = 100; i <= 200; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (0 == i % j)
                break;
        }
        if (i == j)
            printf("%d\n", i);
    }
}
