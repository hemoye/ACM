#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b;

    while (scanf("%f %f", &a, &b) != EOF)
        printf("%.2f\n", fabs(a - b) / (a * b));

    return 0;
}
