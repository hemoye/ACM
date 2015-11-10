#include <stdio.h>

int main(void)
{
    int t, m, n;

    scanf("%d", &m);
    for (t = 1; t <= m; t++)
    {
        scanf("%d", &n);
        int i, j, a[n][n];
        int flage = 1;

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]);

        for (i = 1; i < n; i++)
            for (j = 0; j < n; j++)
            {
                a[i][j-1] = a[i][j];
                a[i-1][j] = a[i][j];
            }

        printf ("Case %d: ", t);

        if (a[0][0] == 1)
        {
            printf ("(0, 0) ");
            flage = 0;
        }
        if (a[0][n-1] == 1)
        {
            printf ("(0, %d) ", n - 1);
            flage = 0;
        }
        if (a[n-1][0] == 1)
        {
            printf ("(%d, 0) ", n - 1);
            flage = 0;
        }
        if (a[n-1][n-1] == 1)
        {
            printf ("(%d, %d) ", n - 1, n - 1);
            flage = 0;
        }
        if (flage)
            printf("oh, smart guys, I can't find anyone!");
        printf("\n");
    }

    return 0;
}
