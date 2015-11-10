#include <stdio.h>
#include <malloc.h>

int main(void)
{
    unsigned T, t;

    scanf("%u", &T);
    for (t = 1; t <= T; t++)
    {
        int n, i, j, temp;
        int * pArry;

        scanf("%d", &n);
        pArry = (int *) malloc (n * sizeof(int));

        for (i = 0; i < n; i++)
            scanf("%d", &pArry[i]);//Êý¾ÝÊäÈë

        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                if (pArry[j] > pArry[j+1])
                {
                    temp = pArry[j];
                    pArry[j] = pArry[j+1];
                    pArry[j+1] = temp;
                }

        printf("Case %d:\n", t);
        for (i = 0; i < n; i++)
            printf((0 == i) ? "%d" : " %d", pArry[i]);
        printf("\n");

        //free(pArry);
    }

    return 0;
}
