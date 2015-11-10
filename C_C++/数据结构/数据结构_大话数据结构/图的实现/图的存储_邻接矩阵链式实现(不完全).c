#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 40
typedef struct                  //�߱���
{
    int adj;                    //���涥���±�
    int weight;                 //����Ȩֵ
    struct EdgeNode * Next;     //������һ���ڽӵ�ĵ�ַ
} EdgeNode;

typedef struct                  //������
{
    int data;                   //���涥����Ϣ
    EdgeNode * FristEdge;       //����ָ��
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

    printf("������ͼ�Ķ������Լ��߻���:");
    scanf("%d%d", &Ver, &Edge);

//    for ( i = 0; i < Ver; i++ )
//        G[i].FristEdge = NULL;

    printf("�����붥��:");
    for ( i = 0; i < Ver; i++ )
        scanf("%d", &G[i].data);
    for ( i = 0; i < Edge; i++)
    {
        EdgeNode * p = ( EdgeNode * )malloc( sizeof( EdgeNode ) );
        printf("������ߣ�Vi,Vj���ڽӵ���Ϣ:");
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

    printf("���еĶ���������ʾ:\n");
    for ( i = 0; i < Ver; i++ )
        printf("%d ", G[i].data);
    puts("");

    for ( i = 0; i < Edge; i++ )
    {
        p = G[i].FristEdge;
        printf("�ýڵ���ڽӵ�Ϊ:");
        while ( p->Next )
        {
            printf("%d ", p->adj);
            p = p->Next;
        }
        puts("");
    }

    return ;
}
