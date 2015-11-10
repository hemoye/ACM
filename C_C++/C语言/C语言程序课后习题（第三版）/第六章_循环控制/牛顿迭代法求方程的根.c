#include <stdio.h>
int main(void)
{
    double x, y;
    x = 1.5;

    while (y)
    {
        y = 2 * x * x * x - 4 * x * x + 3 * x - 6;
        x = x - y / (6 * x * x - 8 * x + 3);
    }

    printf("x = %.3f\n", x);
}
