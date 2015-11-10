#include<stdio.h>

int main(void)
{
    int n,m,i,j,sum;
    int t = 0, t1,t2;//定义声明

    while (scanf("%d",&n) != EOF)
    {
        sum = 0;//初始化变量
        for (i = 1; i < n-1; i++)
            for (j = i+1; j < n; j++)
                if (sum < (i+1) * (j-i+1) * (n-j))//取得最多的金钱数目
                {
                    t1 = i;
                    t2 = j;
                    sum = (i+1)*(j-i+1)*(n-j);//所能赚的的全部金钱
                }
        printf("Case %d:\n",++t);

        printf("%d %d\n",t1,t2);
    }

    return 0;
}
