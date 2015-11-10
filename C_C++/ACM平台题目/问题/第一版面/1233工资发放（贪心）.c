#include <stdio.h>

int main(void)
{
    int i, num = 0, sum;
    int a[7][2] = {{100, 0},{50, 0},{20, 0},{10, 0},{5, 0},{2, 0},{1, 0}};

    scanf("%d", &sum);

    while (sum)
    {
        a[num][1] = sum / a[num][0];
        sum %= a[num][0];
        num++;
    }
    for (i = 0; i < 7; i++)
        printf((i < 6) ? "%d " : "%d\n", a[i][1]);

    return 0;
}
