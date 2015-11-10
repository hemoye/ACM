#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, n, i;
    float y;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a < -2)
            y = a * a - sin(a);
        else if (a >= -2 && a <= 2)
            y = 2 * a + a;
        else
            y = a * a + a + 1;

        printf("%.2f\n", y);
    }

    return 0;
}
