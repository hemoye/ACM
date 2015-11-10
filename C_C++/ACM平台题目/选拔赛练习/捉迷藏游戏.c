#include <stdio.h>

int main(void)
{
    int t, m, n;

    scanf("%d", &m);
    for (t = 1; t <= m; t++)
    {
        scanf("%d", &n);
        int i, j, x, y, a[n][n];
        int flage = 1;
        char str[n][n];

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                if (a[i][j] == 0)
                {
                    if (i == 0)
                    {
                        if (j == 0)
                        {
                            for (x = i; x <= i + 1; x++)
                                for (y = j; y <= j + 1; y++)
                                    str[x][y] = 'I';
                        }
                        else if (j == n - 1)
                        {
                            for (x = i; x <= i + 1; x++)
                                for (y = j - 1; y <= j; y++)
                                    str[x][y] = 'I';
                        }
                        else
                        {
                            for (x = i; x <= i + 1; x++)
                                for (y = j - 1; y <= j + 1; y++)
                                    str[x][y] = 'I';
                        }
                    }
                    else if (i == n - 1)
                    {
                        if (j == 0)
                        {
                            for (x = i - 1; x <= i; x++)
                                for (y = j; y <= j + 1; y++)
                                    str[x][y] = 'I';
                        }
                        else if (j == n - 1)
                        {
                            for (x = i - 1; x <= i; x++)
                                for (y = j - 1; y <= j; y++)
                                    str[x][y] = 'I';
                        }
                        else
                        {
                            for (x = i - 1; x <= i; x++)
                                for (y = j - 1; y <= j + 1; y++)
                                    str[x][y] = 'I';
                        }
                    }
                    else
                    {
                        if (j == 0)
                        {
                            for (x = i - 1; x <= i + 1; x++)
                                for (y = j; y <= j + 1; y++)
                                    str[x][y] = 'I';
                        }
                        else if (j == n - 1)
                        {
                            for (x = i - 1; x <= i + 1; x++)
                                for (y = j - 1; y <= j; y++)
                                    str[x][y] = 'I';
                        }
                        else
                        {
                            for (x = i - 1; x <= i + 1; x++)
                                for (y = j - 1; y <= j + 1; y++)
                                    str[x][y] = 'I';
                        }
                    }
                }
                else
                {
                    if (i == 0)
                    {
                        if (j == 0)
                        {
                            for (x = i; x <= i + 1; x++)
                                for (y = j; y <= j + 1; y++)
                                    str[x][y] = 'T';
                        }
                        else if (j == n - 1)
                        {
                            for (x = i; x <= i + 1; x++)
                                for (y = j - 1; y <= j; y++)
                                    str[x][y] = 'T';
                        }
                        else
                        {
                            for (x = i; x <= i + 1; x++)
                                for (y = j - 1; y <= j + 1; y++)
                                    str[x][y] = 'T';
                        }
                    }
                    else if (i == n - 1)
                    {
                        if (j == 0)
                        {
                            for (x = i - 1; x <= i; x++)
                                for (y = j; y <= j + 1; y++)
                                    str[x][y] = 'T';
                        }
                        else if (j == n - 1)
                        {
                            for (x = i - 1; x <= i; x++)
                                for (y = j - 1; y <= j; y++)
                                    str[x][y] = 'T';
                        }
                        else
                        {
                            for (x = i - 1; x <= i; x++)
                                for (y = j - 1; y <= j + 1; y++)
                                    str[x][y] = 'T';
                        }
                    }
                    else
                    {
                        if (j == 0)
                        {
                            for (x = i - 1; x <= i + 1; x++)
                                for (y = j; y <= j + 1; y++)
                                    str[x][y] = 'T';
                        }
                        else if (j == n - 1)
                        {
                            for (x = i - 1; x <= i + 1; x++)
                                for (y = j - 1; y <= j; y++)
                                    str[x][y] = 'T';
                        }
                        else
                        {
                            for (x = i - 1; x <= i + 1; x++)
                                for (y = j - 1; y <= j + 1; y++)
                                    str[x][y] = 'T';
                        }
                    }
                }
            }
        printf ("Case %d: ", t);
        if (str[0][0] == 'T')
        {
            printf ("(0, 0) ");
            flage = 0;
        }
        if (str[0][n-1] == 'T')
        {
            printf ("(0, %d) ", n - 1);
            flage = 0;
        }
        if (str[n-1][0] == 'T')
        {
            printf ("(%d, 0) ", n - 1);
            flage = 0;
        }
        if (str[n-1][n-1] == 'T')
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
