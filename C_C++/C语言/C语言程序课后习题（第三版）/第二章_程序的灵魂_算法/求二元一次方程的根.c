#include <stdio.h>
#include <math.h>
int main(void)
{
    int a, b, c, detal;
    float x1, x2;

    scanf("%d %d %d", &a, &b, &c);
    detal = b * b - 4 * a * c;

    if (detal > 0)
    {
        x1 = (-b - sqrt(detal)) / (2.0 * a);
        x2 = (-b + sqrt(detal)) / (2.0 * a);

        printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
    else if (detal == 0)
    {
        x1 = x2 = (-b + sqrt(detal)) / (2.0 * a) ;

        printf("x1 = x2 = %.2f\n", x1) ;
    }
    else
        printf("此方程无解！\n");
}
