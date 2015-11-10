#include <stdio.h>

void student(int (*p)[3])
{
    int i, j;
    float sum;
    for (i = 0; i < 5; i++)
    {
        sum = 0;
        for (j = 0; j < 3; j++)
            sum += p[i][j];
        printf("%.1f ", sum / 3);
    }
    return ;
}
void subject(int (*p)[3])
{
    int i, j;
    float sum;
    for (i = 0; i < 3; i++)
    {
        sum = 0;
        for (j = 0; j < 5; j++)
            sum += p[j][i];
        printf("%.1f ", sum / 5);
    }
    return ;
}
int main(void)
{
    int i, j, a[5][3];

    for (i = 0; i < 5; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    student(a[0]);
    puts("");
    subject(a[0]);
    puts("");

    return 0;
}
