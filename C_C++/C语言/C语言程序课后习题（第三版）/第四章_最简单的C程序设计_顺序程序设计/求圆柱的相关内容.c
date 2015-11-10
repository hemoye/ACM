#include <stdio.h>
#define PI 3.14
int main(void)
{
    float r, h;
    float C, S1, S2, V1, V2;

    scanf("%f %f", &r, &h);
    C = 2 * PI * r;//圆周长
    S1 = PI * r * r;//圆面积
    S2 = 4 * PI * r * r;//球表面积
    V1 = PI * r * r * r * 4 / 3;//球体积
    V2 = S1 * h;//圆柱体积

    printf("%.2f %.2f %.2f %.2f %.2f\n", C, S1, S2, V1, V2);
}
