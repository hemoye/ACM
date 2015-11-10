#include <stdio.h>

int sum(int (*p)[4], int i, int j)
{
    int sum = 0;

    if (i == 3)
        while (i >= 0)
            sum += p[i--][j++];
    else
        while (i < 4)
            sum += p[i++][j++];

    return sum;
}
int main(void)
{
    int i, j;
    int a[4][4];

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);
    printf("%d %d\n", sum(a, 0, 0), sum(a, 3, 0));

    return 0;
}
