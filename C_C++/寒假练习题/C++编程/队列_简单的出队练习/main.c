#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXSIZE 40
#define  OUT "OUT"
#define  IN  "IN"

typedef struct
{
    char data[MAXSIZE];
    struct QNode * Next;
} QNode, *QNodePtr;

typedef struct
{
    QNode * front;
    QNode * rear;
} LinkQueue;

void Init( LinkQueue * );              //函数:初始化队列
void EnQueue( LinkQueue * );           //函数：入队
void  DeQueue( LinkQueue * );           //函数：出队
void Traverse( LinkQueue * );          //函数：遍历队列
int  QueueLength( LinkQueue * );       //函数：计算队列长度
int  Judge( LinkQueue * );             //函数：判断队列是否已满

int main( void )
{
    LinkQueue Q;
    char str[MAXSIZE];
    int  n;

    Init( &Q );

    scanf("%d", &n);

    while ( n-- )
    {
        scanf ("%s", str);
        if ( 0 == strcmp( str, IN ) )
            EnQueue( &Q );
        else if ( 0 == strcmp( str, OUT ) )
            DeQueue( &Q );
    }

    return 0;
}
void Init( LinkQueue * Q )
{
    Q->front = ( QNodePtr )malloc( sizeof( QNode ) );
    Q->rear = Q->front = NULL;

    return ;
}
void EnQueue( LinkQueue * Q )
{
    QNodePtr temp = ( QNodePtr )malloc( sizeof( QNode ) );

    scanf("%s", temp->data);
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
void DeQueue( LinkQueue * Q )
{
    QNodePtr temp;
    char str[MAXSIZE];

    if ( Q->rear == Q->front )
    {
        printf("出队失败！该队列为空队列！\n");
        getch();
        return ;
    }
    for ( temp = Q->rear; temp->Next != Q->front; temp = temp->Next );

    printf("%s\n", temp->data);
    Q->front = temp;

    return ;
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

