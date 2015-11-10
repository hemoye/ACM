#include <stdio.h>
int main(void)
{
    int i, n, a, b, c;

    for (i = 101; i < 1000; i++)
    {
        a = i % 10;
        b = (i / 10) % 10;
        c = i / 100;
        n = a * a * a + b * b * b + c * c * c;

        if (i == n)
            printf("%d ", i);
    }
    printf("\n");
}
