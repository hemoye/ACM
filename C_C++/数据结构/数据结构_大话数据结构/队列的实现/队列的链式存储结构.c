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
void Traverse( LinkQueue * );          //函数：遍历队列
int  QueueLength( LinkQueue * );       //函数：计算队列长度
int  Judge( LinkQueue * );             //函数：判断队列是否已满

int main( void )
{
    LinkQueue Q;
    int n;

    Init( &Q );

    while ( 1 )
    {
        scanf("%d", &n);
        if ( 0 == n )
            break;
        EnQueue( &Q, n );
    }

    printf("此队列的长度为:%d\n", QueueLength( &Q ));
    printf("遍历此队列所有元素如下:\n");
    Traverse( &Q );
    puts("");

    if ( Judge( &Q ) )
        printf("出队失败！队列为空！\n");
    else
        printf("此次出队的元素为:%d\n", DeQueue( &Q ));

    printf("此队列的长度为:%d\n", QueueLength( &Q ));
    printf("遍历此队列所有元素如下:\n");
    Traverse( &Q );
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
void Traverse( LinkQueue * Q )
{
    QNodePtr temp1;
    QNodePtr temp2;
    temp2 = Q->front;

    if ( temp2 == Q->rear )
    {
        printf("遍历失败！该队列为空队列！\n");
        getch();
        return ;
    }

    while ( temp2 != Q->rear )
    {
        for ( temp1 = Q->rear; temp1->Next != temp2; temp1 = temp1->Next );
        temp2 = temp1;
        printf("%d ", temp1->data);
    }

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
    Q->front = temp;

    return x;
}
int QueueLength( LinkQueue * Q )
{
    QNodePtr temp;
    int len = 0;
    temp = Q->rear;

    while ( temp != Q->front )
    {
        temp = temp->Next;
        len++;
    }
    return len;
}
int Judge( LinkQueue * Q )
{
    if ( Q->front == Q->rear )
        return 1;
    return 0;
}

