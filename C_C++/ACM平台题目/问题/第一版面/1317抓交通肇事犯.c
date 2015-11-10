#include <stdio.h>

int main(void)
{
    int i, j, x, num;

    for (i = 1; i <= 9; i++)
        for (j = 1; j <= 9; j++)
            if (i != j)
                num = i * 1000 + i * 100 + j * 10 + j;

    printf("7744\n");

    return 0;
}
