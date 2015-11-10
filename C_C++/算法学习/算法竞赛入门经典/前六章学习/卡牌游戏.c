#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct QNode * Next;
} QNode, *QNodePtr;

typedef struct
{
    QNode * front;
    QNode * rear;
} LinkQueue;

void Init( LinkQueue * );              //函数:初始化队列
void EnQueue( LinkQueue * , int );     //函数：入队
int  DeQueue( LinkQueue * );           //函数：出队

int main( void )
{
    LinkQueue Q;
    int n, m;
    int i = 0;

    Init( &Q );

    printf("How many number do you want to enter: ");
    scanf("%d", &m );

    while ( i++ < m )
    {
        scanf("%d", &n );
        EnQueue( &Q, n );
    }

    printf("The order of dequeue is : ");
    for ( i = 0; i < m; i++ )
    {
        printf("%d ", DeQueue( &Q ) );

        if ( i < m - 1 )
            EnQueue( &Q, DeQueue( &Q ) );
    }
    puts("");

    return 0;
}
void Init( LinkQueue * Q )
{
    Q->front = ( QNodePtr )malloc( sizeof( QNode ) );
    Q->rear = Q->front = NULL;

    return ;
}
void EnQueue( LinkQueue * Q, int n )
{
    QNodePtr temp = ( QNodePtr )malloc( sizeof( QNode ) );

    temp->data = n;
    temp->Next = Q->rear;
    Q->rear = temp;

    return ;
}
int DeQueue( LinkQueue * Q )
{
    QNodePtr temp;
    int x;

    if ( Q->rear == Q->front )
    {
        printf("出队失败！该队列为空队列！\n");
        getch();
        return ;
    }
    for ( temp = Q->rear; temp->Next != Q->front; temp = temp->Next );

    x = temp->data;
    free( Q->front );
    Q->front = temp;

    return x;
}
