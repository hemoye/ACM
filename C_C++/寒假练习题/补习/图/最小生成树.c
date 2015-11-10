#include <stdio.h>
#include <string.h>
#define MAXN 100
#define INF 65535
int n = 9;
int G[MAXN][MAXN] =
{
    {0, 10, INF, INF, INF, 11, INF, INF, INF},
    {10, 0, 18, INF, INF, INF, 16, INF, 12},
    {INF, INF, 0, 22, INF, INF, INF, INF, 8},
    {INF, INF, 22, 0, 20, INF, INF, 16, 21},
    {INF, INF, INF, 20, 0, 26, INF, 7, INF},
    {11, INF, INF, INF, 26, 0, 17, INF, INF},
    {INF, 16, INF, INF, INF, 17, 0, 19, INF},
    {INF, INF, INF, 16, 7, INF, 19, 0, INF},
    {INF, 12, 8, 21, INF, INF, INF, INF, 0}
};
/*Prim算法最小生成树*/
void MiniSpanTree_Prim(void)
{
    int min, i, j, k;
    int adjvex[MAXN];   //保存相关顶点的下标
    int lowcost[MAXN];  //保存相关顶点间边的权值

    lowcost[0] = 0;   //初始化第一个权值为0.即v0加入生成树
    /*lowcost 的值为0，在这里就是此下标的顶点已经加入到生成树*/
    adjvex[0] = 0;   //初始化第一个顶点下标为0

    for(i = 1; i < n; i ++)      //循环下标为0外的全部顶点
    {
        lowcost[i] = G[0][i];   //将v0顶点与之有关的权值存入数组
        adjvex[i] = 0;   //初始化都为v0的下标
    }
    for(i = 1; i < n; i ++)
    {
        min = INF;     //初始化最小权值为∞
        j = 1;
        k = 0;
        while( j < n )
        {
            if( lowcost[j] != 0 && lowcost[j] < min )    //权值不为0且权值小于min
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d, %d) %d\n", adjvex[k], k, lowcost[k]);    //打印顶点边中权值最小的边
        lowcost[k] = 0;   //将当前顶点的权值设置为0，表示此顶点已经完成任务
        for(j = 1; j < n; j ++)
        {
            if( lowcost[j] != 0 && G[k][j] < lowcost[j] )
            {
                /*若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值*/
                lowcost[j] = G[k][j];    //将较小的权值存入lowcost
                adjvex[j] = k;    //将下标为k的顶点存入adjvex
            }
        }
    }
}
int main(void)
{
    MiniSpanTree_Prim();
    return 0;
}
