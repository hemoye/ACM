/*kruskal 算法是根据边的权值以递增的方式，依次
找出权值最低的边来建最小生成树，规定每次添加的
边不能造成生产树有回路。

比如，一个图中所有边按权值递增的排序如下：
(4,5)2  (3,4)3  (1,4)5  (1,3)6 (1,2)7
(2,4)8  (2,5)8  (3,5)9  (1,5)12  (2,3)14

步骤1：将(4,5)的边加到生产树中
步骤2：将(3,4)的边加到生产树中
步骤3：将(1,4)的边加到生产树中
步骤4：将(1,3)的边加到生产树中，但发现这时出现了
       回路(1,3,4 顶点)，我们改用下条边(1,2)加到
       生产树中,现在已经连通了1 2 3 4 5 所有顶点，
       最小生产树建立完成。

下面看程序，读入一个带权连通无向图G，生产最小生产树T，输出T的各边及各边的权之和。输入形式如下：
n  i  j  w  ...  -1 -1 -1

n表示图的顶点个数，i j w 表示从顶点i 到顶点j 的权为w 的一条边。
我们的做法是读入一条边后按照权值由小到大的顺序把这条边插入链表，然后从链表中读边生产树。
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 100

struct Node
{   //边的链表表示
    int vertex1;
    int vertex2;
    int weight;
    struct Node *next;
};
typedef struct Node *Edge;
Edge head = NULL;       //边的头指针为空
int visited[MAX];       //

Edge read()
{   //写入边的信息，并排序
    int v1, v2, w;
    Edge newNode = NULL, pointer = NULL;
    while(1)
    {
        scanf("%d %d %d", &v1, &v2, &w);//输入边的第一个节点、第二个节点、权值
        if(v1 == -1 || v2 == -1 || w == -1)
            break;
        newNode = (Edge)malloc(sizeof(struct Node));//申请空间
        newNode->vertex1 = v1;//赋值给新节点的变量
        newNode->vertex2 = v2;
        newNode->weight = w;
        newNode->next = NULL;//链表指针结束
        pointer = head;//让pionter也指向新的链表
        if(pointer == NULL)
            head = newNode;
        else
        {
            if(newNode->weight < pointer->weight)
            {
                newNode->next = pointer;
                head = newNode;
            }
            else
            {
                while(pointer != NULL && pointer->next != NULL)
                {
                    if(pointer->weight < newNode->weight
                            && newNode->weight < pointer->next->weight)
                    {
                        newNode->next = pointer->next;
                        pointer->next = newNode;
                        break;
                    }
                    pointer = pointer->next;
                }
                pointer->next = newNode;
            }
        }
    }
    return head;
}

void printLink(Edge edge)
{
    Edge pointer = edge;
    printf("\n\nEdge link : \n");
    while(pointer != NULL)
    {
        printf("[%d %d]", pointer->vertex1, pointer->vertex2);
        printf("(%d)",pointer->weight);
        if(pointer->next != NULL)
            printf(" ==> ");
        pointer = pointer->next;
    }
    printf("\n");
}

void kruskal(Edge edge, int vexnum)
{
    int visitedEdgeNum = 0, weight = 0;
    printf("\nMin generate tree : \n");
    while(visitedEdgeNum < vexnum)
    {
        if(visited[edge->vertex1] == 0 || visited[edge->vertex2] == 0)
        {
            printf("[%d %d]", edge->vertex1, edge->vertex2);
            printf("(%d) ",edge->weight);
            weight += edge->weight;
            visitedEdgeNum++;
            visited[edge->vertex1] = 1;
            visited[edge->vertex2] = 1;
        }
        edge = edge->next;
        if(edge == NULL)
        {
            break;
        }
    }
    printf("\n\nTotal weight = %d \n\n", weight);
}

int main( int agrc, char *agrv[] )
{
    int vexnum, i;
    Edge edge = NULL;
    printf("enter vexnum and edges with weight: \n");
    scanf("%d", &vexnum);
    for(i=0; i<vexnum; i++)
        visited[i] = 0;
    edge = read();
    printLink(edge);
    kruskal(edge, vexnum);
}
