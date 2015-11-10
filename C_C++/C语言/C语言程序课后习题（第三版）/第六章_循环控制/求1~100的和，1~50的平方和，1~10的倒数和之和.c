#include <stdio.h>
int main(void)
{
    int a, b, c, i;
    float x, y, z, sum;
    x = y = z = 0;

    scanf("%d %d %d", &a, &b, &c);

    for (i = 1; i <= a; i++)
        x += i;
    for (i = 1; i <= b; i++)
        y += i * i;
    for (i = 1; i <= c; i++)
        z += 1.0 / i;

    sum = x + y + z;
    printf("%.2f\n", sum);
}
