#include <stdio.h>

int main(void)
{
    int h[10], l, i, num = 0;


    for (i = 0; i < 10; i++)
        scanf("%d", &h[i]);
    scanf("%d", &l);

    for (i = 0; i < 10; i++)
        if (l + 30 >= h[i])
            num++;
    printf("%d\n", num);

    return 0;
}
