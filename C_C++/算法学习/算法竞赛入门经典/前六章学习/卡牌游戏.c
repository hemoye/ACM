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

void Init( LinkQueue * );              //����:��ʼ������
void EnQueue( LinkQueue * , int );     //���������
int  DeQueue( LinkQueue * );           //����������

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
        printf("����ʧ�ܣ��ö���Ϊ�ն��У�\n");
        getch();
        return ;
    }
    for ( temp = Q->rear; temp->Next != Q->front; temp = temp->Next );

    x = temp->data;
    free( Q->front );
    Q->front = temp;

    return x;
}
