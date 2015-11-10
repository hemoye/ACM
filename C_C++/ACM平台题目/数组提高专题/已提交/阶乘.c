#include<stdio.h>

int main(void)
{
    int fac[1000], add[1000];
    int top = 0, n, i, j;

    scanf("%d",&n);

    memset(fac, 0, 1000);
    memset(add, 0, 1000);

    fac[0]=1;//结果数组

    for(i=1; i<=n; i++)
    {
        /*计算进位数组add*/
        for(j = 0; j <= top; j++)
        {
            fac[j] = fac[j] * i;
            if(j == 0)
                add[j] = fac[j] / 10;
            else
                add[j]=(fac[j] + add[j-1]) / 10;
        }
        /*更新top的值*/
        if(add[top] >= 0)
            top++;
        /*计算结果数组fac*/
        for(j = 0; j <= top; j++)
        {
            if(j == 0)
                fac[j] = fac[j] % 10;
            else
                fac[j] = (fac[j] + add[j-1]) % 10;
        }
    }
    /*输出结果数组fac*/
    for(j = top - 1; j >= 0; j--)
        printf("%d",fac[j]);
    printf("\n");

    return 0;
}
