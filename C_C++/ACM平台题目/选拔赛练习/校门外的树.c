#include <stdio.h>

int main(void)
{
    int i, j, L, M, tree = 0;

    scanf("%d %d", &L, &M);
    int sum[L+1], a[M][2];

    for (i = 0; i <= L; i++)
        sum[i] = 1;
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
        for (j = a[i][0]; j <= a[i][1]; j++)
            sum[j] = 0;
    }
    for (i = 0; i <= L; i++)
        tree += sum[i];

    printf("%d\n", tree);

    return 0;
}
