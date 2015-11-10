#include <stdio.h>
int main(void)
{
    int i, j;
    long int s = 1, sum = 0;

    for (i = 1; i <= 20; i++)
    {
        s = 1;
        for (j = 1; j <= i; j++)
            s *= j;
        sum += s;
    }

    printf("%ld\n", sum);
}
