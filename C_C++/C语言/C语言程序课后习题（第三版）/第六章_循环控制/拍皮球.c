#include <stdio.h>
int main(void)
{
    int n, i;
    float s = 100, h = 100;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        h = h / 2.0;
        s += h;
    }

    printf("%.2f %.2f\n", s, h);
}
