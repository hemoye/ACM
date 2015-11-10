#include <stdio.h>
int main(void)
{
    int a, b, max;

    scanf("%d %d", &a, &b);
    max = (a > b) ? a : b;

    printf("max=%d", max);

    return 0;
}
