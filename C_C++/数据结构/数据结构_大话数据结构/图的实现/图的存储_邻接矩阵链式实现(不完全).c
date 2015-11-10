#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 40
typedef struct                  //边表结点
{
    int adj;                    //储存顶点下标
    int weight;                 //储存权值
    struct EdgeNode * Next;     //储存下一个邻接点的地址
} EdgeNode;

typedef struct                  //顶点结点
{
    int data;                   //储存顶点信息
    EdgeNode * FristEdge;       //顶点指针
} VertexNode;

VertexNode G[MAXSIZE];
int Ver, Edge;
void Creat_Graph( void );
void Traverse_Graph( void );

int main( void )
{
    Creat_Graph();
    Traverse_Graph();

    return 0;
}
void Creat_Graph( void )
{
    int i, j;

    printf("请输入图的顶点数以及边或弧数:");
    scanf("%d%d", &Ver, &Edge);

//    for ( i = 0; i < Ver; i++ )
//        G[i].FristEdge = NULL;

    printf("请输入顶点:");
    for ( i = 0; i < Ver; i++ )
        scanf("%d", &G[i].data);
    for ( i = 0; i < Edge; i++)
    {
        EdgeNode * p = ( EdgeNode * )malloc( sizeof( EdgeNode ) );
        printf("请输入边（Vi,Vj）邻接点信息:");
        scanf("%d", &p->adj);
        p->Next = G[i].FristEdge;
        G[i].FristEdge = p;
    }

    return ;
}
void Traverse_Graph( void )
{
    int i, j;
    EdgeNode * p = ( EdgeNode * )malloc( sizeof( EdgeNode ) );

    printf("所有的顶点如下所示:\n");
    for ( i = 0; i < Ver; i++ )
        printf("%d ", G[i].data);
    puts("");

    for ( i = 0; i < Edge; i++ )
    {
        p = G[i].FristEdge;
        printf("该节点的邻接点为:");
        while ( p->Next )
        {
            printf("%d ", p->adj);
            p = p->Next;
        }
        puts("");
    }

    return ;
}
