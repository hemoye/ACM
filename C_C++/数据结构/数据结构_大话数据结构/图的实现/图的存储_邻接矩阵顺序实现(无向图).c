#include <stdio.h>
#include <stdlib.h>
#define INF '0'
#define MAX 100

typedef struct
{
    char ver[MAX];              //顶点表
    char arc[MAX][MAX];         //边数组
    int  NumVer, NumEdge;       //顶点个数、以及边的条数
} Graph;

int main( void )
{
    Graph G;
    int i, j, v;

    printf("请输入当前该图的顶点数与边数：");
    scanf("%d %d", &G.NumVer, &G.NumEdge);

    printf("请输入该图的所有顶点:");
    for ( i = 0; i < G.NumVer; i++ )
        scanf(" %c", &G.ver[i]);

    for ( i = 0; i < G.NumVer; i++ )
        for ( j = 0; j < G.NumVer; j++ )
            G.arc[i][j] = INF;

    for ( v = 0; v < G.NumEdge; v++ )
    {
        printf("请输入边(Vi,Vj)的上标i及其下标j:");
        scanf("%d %d", &i, &j);
        G.arc[j][i] = G.arc[i][j] = INF + 1;
    }

    printf("该图的所有顶点如下:\n");
    for ( i = 0; i < G.NumVer; i++ )
        printf("%c ", G.ver[i]);
    puts("");

    printf("该图的邻接矩阵如下所示:\n");
    for ( i = 0; i < G.NumVer; i++ )
    {
        for ( j = 0; j < G.NumVer; j++ )
            printf("%c ", G.arc[i][j]);
        puts("");
    }

    return 0;
}
