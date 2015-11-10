#include <stdio.h>
#define N 100

int a[N],end;//定义外部变量

void zuhe(int , int );//从m个元素中取出k个元素的组合

int main(void)
{
    int n,m;

    scanf("%d%d",&n,&m);
    end = m;
    zuhe(n, m);

    return 0;
}
void zuhe(int n,int m)//从m个元素中取出k个元素的组合
{
    int i, j;//声明语句

    for(i = 1; i <= n; i++)
    {
        a[m] = i;//最后一个位置的元素可以取m,m-1,m-2.....k

        if(m > 1)
            zuhe(i-1, m-1);//递归调用
        else
        {
            for(j = 1; j <= end; j++)
                printf((1 == j) ? "%d" : " %d",a[j]);
            printf("\n");
        }
    }
}
