#include <stdio.h>
#include <string.h>
#define MAX 100
int n, tot = 0;
int a[MAX], vis[MAX][MAX];
void search1(int pos)
{
    int i, j;
    if ( pos == n )	tot ++;
    else
    {
        for (i = 0; i < n; i ++)
        {
            /*
            	这里的数组相对于前一个方法是把前一个方法要判断的东西写入二组数组里
            */
            if ( !vis[0][i] && !vis[1][pos+i] && !vis[2][pos-i+n] )
            {
                //利用二维数组直接判断
                a[pos] = i;   //如果不用打印解，整个a数组都可以省略
                vis[0][i] = vis[1][pos+i] = vis[2][pos-i+n] = 1;  //修改全局变量
                //注意到主对角线标识y-x可能为负，存取时要加上n
                search1(pos+1);
                vis[0][i] = vis[1][pos+i] = vis[2][pos-i+n] = 0;  //改回来
            }
        }
    }
}
int main(void)
{
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    search1(0);
    printf("%d\n", tot);
    return 0;
}
