#include <stdio.h>
#include <math.h>
int main(void)
{
    float x, n;

    scanf("%d %d", &x, &n);

    n = cos(x);

    printf("%.4f", n);

    return 0;
}
