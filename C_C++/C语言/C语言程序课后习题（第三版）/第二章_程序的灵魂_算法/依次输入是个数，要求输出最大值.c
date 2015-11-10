#include <stdio.h>
int main(void)
{
    int a, i, b = 0;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a);
        b = (a > b) ? a : b;
    }
    printf("%d\n", b);
}
