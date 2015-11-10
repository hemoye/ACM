#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#define MAXNUM_VERTEX 20 //最多有 20个顶点
#define MAXNUM_EDGE 21
typedef struct
{
    int v,w;
    int weight;
} Edge;
typedef struct
{
    int vertex[MAXNUM_VERTEX];
    Edge edge[MAXNUM_EDGE];
    int num_vertex,num_edge;
} Graph;
Graph graph; //声明为全局变量
bool search_vertex(int ver)
{
    for(int i=0; i<graph.num_vertex; i++)
        if( ver == graph.vertex[i] )
            return 1;
    printf("the vertex %d you input is not existed! \n",ver);
    return 0;
}
void create_graph()
{
//输入顶点信息
    printf("input the number of vertex in the graph\n");
    scanf(" %d",&graph.num_vertex);
    printf("input the vertex of graph,like 1,2\n");
    for(int i=0; i<graph.num_vertex; i++)
        scanf(" %d",&graph.vertex[i]);
//输入边信息
    printf("input the number of edge in the graph\n");
    scanf(" %d",&graph.num_edge);
    printf("intput the edge of graph and the weight of line,like 1-2 5\n");
    for(int j=0; j<graph.num_edge; j++)
    {
p1:
        int a,c,d;
        char b;
        scanf(" %d %c %d %d",&a,&b,&c,&d);
        if( search_vertex(a) && search_vertex(c) )
        {
            graph.edge[j].v=a;
            graph.edge[j].w=c;
            graph.edge[j].weight=d;
        }
        else
            goto p1;
    }
}
void sort_by_weight()
{
    int j;
    for(int i=1; i<graph.num_edge; i++)
    {
        Edge temp=graph.edge[i];
        for( j=i-1; j>=0 && graph.edge[j].weight>temp.weight; j--)
            graph.edge[j+1]=graph.edge[j];
        graph.edge[j+1]=temp;
    }
}
/*不相交集处理函数*/
inline void makeset(vector<int> & array)
{
    for(int i=0; i<array.size(); i++)
        array[i]=i;
}
int findset(vector<int> & parent,int i)
{
    if(i != parent[i])
        i=parent[i];
    return i;
}
inline void merge(vector<int> & parent,int i,int j)
{
    parent[i]=j;
}
/*不相交集处理函数*/
void kruskal()
{
    int num_ver=graph.num_vertex;
    int count=0;
    vector<int> parent_ver;
    parent_ver.resize(num_ver);
    /*核心部分是用不相交集合成树*/
    makeset(parent_ver);
    printf("the edge of min tree as follow: \n");
    for( int i=0; i<num_ver && count<num_ver-1; i++ ) //count表示合并（merge）的次数num_ver-1次
    {
        int m=graph.edge[i].v;
        int n=graph.edge[i].w;
        int w=graph.edge[i].weight;
        if( findset(parent_ver,m) != findset(parent_ver,n)) //当属于不同的集合时，则将该边添加进树中
        {
            printf("(%d %d) %d\n",m,n,w);
            merge(parent_ver,m,n);
            count++;
        }
    }
}
void print_edge()
{
    printf("the graph you input as follow: \n");
    for(int i=0; i<graph.num_edge; i++)
        printf("%d-%d the weight is: %d\n",graph.edge[i].v,graph.edge[i].w,graph.edge[i].weight);
}
int main( void )
{
    sort_by_weight();
    print_edge();
    kruskal();
    return 0;
}
