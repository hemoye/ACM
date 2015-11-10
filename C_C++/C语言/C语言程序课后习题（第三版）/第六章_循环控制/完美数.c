#include <stdio.h>
int M(int x)
{
    int i, sum = 0;

    for (i = 1; i < x; i++)
        if (0 == x % i)
            sum += i;
    if (sum == i)
        return sum;
    else
        return 0;
}
int main(void)
{
    int i, j;

    for (i = 1; i <= 1000; i++)
        if (M(i))
        {
            printf("%d its factors are ", M(i));
            for (j = 1; j < M(i); j++)
                if (0 == M(i) % j)
                    printf("%d,", j);
            printf("\n");
        }
}
