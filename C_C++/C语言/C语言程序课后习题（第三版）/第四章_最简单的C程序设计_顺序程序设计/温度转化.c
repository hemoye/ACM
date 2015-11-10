#include <stdio.h>
int main(void)
{
    float c, f;

    scanf("%f", &f);
    c = (f - 32) * 5 / 9.0;

    printf("%.2f", c);
}
