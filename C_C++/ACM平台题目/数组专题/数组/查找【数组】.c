#include <stdio.h>

void search(int * p, int m, int n)
{
    int a[n+1];
    int i, j, time = 0, temp;
    for (i = 0; i < m; i++)
        a[i] = p[i];
    for (i = 0; i < m - 1; i++)
        for (j = 0; j < m - 1 - i; j++)
            if (p[j] > p[j+1])
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
    for (j = 0; j < m; j++)
        for (i = 0; i < n; i++)
            if (a[j] == p[i])
            {
                time++;
                printf((time == 1) ? "%d" : " %d", p[i]);
            }
    puts("");
}

int main(void)
{
    int m, n, x;
    int a[8];
    for (m = 0; m < 8; m++)
        scanf("%d", &a[m]);
    scanf("%d %d", &x, &n);
    search(a, x, n);

    return 0;
}
