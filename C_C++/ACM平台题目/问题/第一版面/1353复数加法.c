#include <stdio.h>

int main(void)
{
    int a, b, c, d, h, i;

    scanf("%d", &h);

    for (i = 0; i < h; i++)
    {
        c = 0;
        scanf("%d", &a);
        for (d = 0; d < a; d++)
        {
            scanf("%d", &b);
            c += b;
        }
        printf("%d\n\n", c);
    }

    return 0;
}
