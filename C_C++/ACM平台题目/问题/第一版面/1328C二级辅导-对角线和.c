#include <stdio.h>

int main(void)
{
    int a[3][3];
    int i, j, sum;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    sum = a[0][0] + a[2][2] + a[1][1];
    printf("%d\n",sum);

    return 0;
}
