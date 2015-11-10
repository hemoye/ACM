#include <stdio.h>
int main(void)
{
    int i, j, a[3][3];

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    j = a[0][2] + a[1][1] + a[2][0];

    printf("%d\n", j);
}
