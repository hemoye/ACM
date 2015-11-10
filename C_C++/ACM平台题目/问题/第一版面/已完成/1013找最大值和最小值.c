#include <stdio.h>

float foundMin(float a, float b);
float foundMax(float c, float d);

int main(void)
{
    float n, c, a[100], b[100];
    int i;

    scanf("%f", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
        foundMin(a[0], a[i]);
    }
    for (i = 0; i < n; i++)
        foundMax(b[0], b[i]);

    printf("%.2f %.2f\n", foundMax(b[0], b[i]), foundMin(a[0], a[i]));

    return 0;
}
float foundMin(float a, float b)
{
    a = (a < b) ? a : b;

    return a;
}
float foundMax(float c, float d)
{
    c = (c > d) ? c : d;

    return c;
}
