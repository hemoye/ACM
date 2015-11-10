#include <stdio.h>

int main(void)
{
    int i, j, sum;

    for (i = 100; i < 1000; i++)
    {
        j = i;
        sum = 0;
        while (j)
        {
            sum = sum * 10 + j % 10;
            j /= 10;
        }
        if (1333 == sum + i)
           printf("%d %d\n", i, sum);
    }

    return 0;
}
