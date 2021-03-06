#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 400

/******构建队列结构体*******/
typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
} Queue;

void Init( Queue * );        //函数:初始化队列
void EnQueue( Queue * , int );     //函数：入队
int  DeQueue( Queue * );     //函数：出队
void Traverse( Queue * );    //函数：遍历队列
int  QueueLength( Queue * ); //函数：计算队列长度
int  Judge( Queue * );       //函数：判断队列是否已满

/************主函数************/
int main( void )
{
    Queue Q;
    int n;

    Init( &Q );

    while ( scanf("%d", &n) != EOF )
    {
        EnQueue( &Q, n );

        printf("%d->", n);
        while ( !Judge( &Q ) )
            printf("%d", DeQueue( &Q ) );
        puts("");
    }

    return 0;
}
/************初始化队列************/
void Init( Queue * Q )
{
    Q->front = Q->rear = 0;

    return ;
}
/************入队函数************/
void EnQueue( Queue * Q, int n )
{
    while ( n )
    {
        if ( ( Q->rear + 1 ) % MAXSIZE == Q->front )
        {
            printf("此次操作失败！队列已满！\n");
            getch();
            return ;
        }

        Q->data[Q->rear] = n % 2;
        n /= 2;
        Q->rear = ( Q->rear + 1 ) % MAXSIZE;
    }
    return ;
}
/************遍历函数************/
void Traverse( Queue * Q )
{
    int temp = Q->front;

    if ( temp == Q->rear )
    {
        printf("遍历失败！此队列为空队列！\n");
        getch();
        return ;
    }
    while ( temp != Q->rear )
    {
        printf("%d ", Q->data[temp] );
        temp = ( temp + 1 ) % MAXSIZE;
    }
    return ;
}
/************出队函数************/
int DeQueue( Queue * Q )
{
    int temp = Q->rear;

    if ( temp == Q->front )
    {
        printf("出队失败！此队列为空队列!\n");
        getch();
        return ;
    }
    Q->rear = ( Q->rear - 1 ) % MAXSIZE;

    return Q->data[temp-1];
}
/************计算队列长度************/
int QueueLength( Queue * Q )
{
    return ( Q->rear - Q->front + MAXSIZE ) % MAXSIZE;
}
/************判断函数************/
/**队列已满则返回真，否则返回假**/
int Judge( Queue * Q )
{
    if ( Q->rear == Q->front )
        return 1;
    return 0;
}
