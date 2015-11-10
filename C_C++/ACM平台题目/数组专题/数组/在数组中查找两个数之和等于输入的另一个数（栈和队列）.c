#include <stdio.h>

int main(void)
{
    int a[6];
    int i, j, m;

    for (i = 0; i < 6; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);

    for (i = 0; i < 5; i++)
        for (j = i + 1; j < 6; j++)
            if (a[i] + a[j] == m)
            {
                printf("%d %d\n", a[i], a[j]);
                return 0;
            }
}
