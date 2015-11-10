#include <stdio.h>
#include <stdlib.h>
#define INF '0'
#define MAX 100

typedef struct
{
    char ver[MAX];              //�����
    char arc[MAX][MAX];         //������
    int  NumVer, NumEdge;       //����������Լ��ߵ�����
} Graph;

int main( void )
{
    Graph G;
    int i, j, v;

    printf("�����뵱ǰ��ͼ�Ķ������������");
    scanf("%d %d", &G.NumVer, &G.NumEdge);

    printf("�������ͼ�����ж���:");
    for ( i = 0; i < G.NumVer; i++ )
        scanf(" %c", &G.ver[i]);

    for ( i = 0; i < G.NumVer; i++ )
        for ( j = 0; j < G.NumVer; j++ )
            G.arc[i][j] = INF;

    for ( v = 0; v < G.NumEdge; v++ )
    {
        printf("�������(Vi,Vj)���ϱ�i�����±�j:");
        scanf("%d %d", &i, &j);
        G.arc[j][i] = G.arc[i][j] = INF + 1;
    }

    printf("��ͼ�����ж�������:\n");
    for ( i = 0; i < G.NumVer; i++ )
        printf("%c ", G.ver[i]);
    puts("");

    printf("��ͼ���ڽӾ���������ʾ:\n");
    for ( i = 0; i < G.NumVer; i++ )
    {
        for ( j = 0; j < G.NumVer; j++ )
            printf("%c ", G.arc[i][j]);
        puts("");
    }

    return 0;
}
