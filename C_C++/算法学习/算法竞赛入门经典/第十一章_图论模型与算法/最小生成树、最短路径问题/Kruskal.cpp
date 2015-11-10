/*kruskal �㷨�Ǹ��ݱߵ�Ȩֵ�Ե����ķ�ʽ������
�ҳ�Ȩֵ��͵ı�������С���������涨ÿ����ӵ�
�߲�������������л�·��

���磬һ��ͼ�����б߰�Ȩֵ�������������£�
(4,5)2  (3,4)3  (1,4)5  (1,3)6 (1,2)7
(2,4)8  (2,5)8  (3,5)9  (1,5)12  (2,3)14

����1����(4,5)�ı߼ӵ���������
����2����(3,4)�ı߼ӵ���������
����3����(1,4)�ı߼ӵ���������
����4����(1,3)�ı߼ӵ��������У���������ʱ������
       ��·(1,3,4 ����)�����Ǹ���������(1,2)�ӵ�
       ��������,�����Ѿ���ͨ��1 2 3 4 5 ���ж��㣬
       ��С������������ɡ�

���濴���򣬶���һ����Ȩ��ͨ����ͼG��������С������T�����T�ĸ��߼����ߵ�Ȩ֮�͡�������ʽ���£�
n  i  j  w  ...  -1 -1 -1

n��ʾͼ�Ķ��������i j w ��ʾ�Ӷ���i ������j ��ȨΪw ��һ���ߡ�
���ǵ������Ƕ���һ���ߺ���Ȩֵ��С�����˳��������߲�������Ȼ��������ж�����������
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 100

struct Node
{   //�ߵ������ʾ
    int vertex1;
    int vertex2;
    int weight;
    struct Node *next;
};
typedef struct Node *Edge;
Edge head = NULL;       //�ߵ�ͷָ��Ϊ��
int visited[MAX];       //

Edge read()
{   //д��ߵ���Ϣ��������
    int v1, v2, w;
    Edge newNode = NULL, pointer = NULL;
    while(1)
    {
        scanf("%d %d %d", &v1, &v2, &w);//����ߵĵ�һ���ڵ㡢�ڶ����ڵ㡢Ȩֵ
        if(v1 == -1 || v2 == -1 || w == -1)
            break;
        newNode = (Edge)malloc(sizeof(struct Node));//����ռ�
        newNode->vertex1 = v1;//��ֵ���½ڵ�ı���
        newNode->vertex2 = v2;
        newNode->weight = w;
        newNode->next = NULL;//����ָ�����
        pointer = head;//��pionterҲָ���µ�����
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
