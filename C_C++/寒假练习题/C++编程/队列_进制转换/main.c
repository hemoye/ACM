#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 400

/******�������нṹ��*******/
typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
} Queue;

void Init( Queue * );        //����:��ʼ������
void EnQueue( Queue * , int );     //���������
int  DeQueue( Queue * );     //����������
void Traverse( Queue * );    //��������������
int  QueueLength( Queue * ); //������������г���
int  Judge( Queue * );       //�������ж϶����Ƿ�����

/************������************/
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
/************��ʼ������************/
void Init( Queue * Q )
{
    Q->front = Q->rear = 0;

    return ;
}
/************��Ӻ���************/
void EnQueue( Queue * Q, int n )
{
    while ( n )
    {
        if ( ( Q->rear + 1 ) % MAXSIZE == Q->front )
        {
            printf("�˴β���ʧ�ܣ�����������\n");
            getch();
            return ;
        }

        Q->data[Q->rear] = n % 2;
        n /= 2;
        Q->rear = ( Q->rear + 1 ) % MAXSIZE;
    }
    return ;
}
/************��������************/
void Traverse( Queue * Q )
{
    int temp = Q->front;

    if ( temp == Q->rear )
    {
        printf("����ʧ�ܣ��˶���Ϊ�ն��У�\n");
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
/************���Ӻ���************/
int DeQueue( Queue * Q )
{
    int temp = Q->rear;

    if ( temp == Q->front )
    {
        printf("����ʧ�ܣ��˶���Ϊ�ն���!\n");
        getch();
        return ;
    }
    Q->rear = ( Q->rear - 1 ) % MAXSIZE;

    return Q->data[temp-1];
}
/************������г���************/
int QueueLength( Queue * Q )
{
    return ( Q->rear - Q->front + MAXSIZE ) % MAXSIZE;
}
/************�жϺ���************/
/**���������򷵻��棬���򷵻ؼ�**/
int Judge( Queue * Q )
{
    if ( Q->rear == Q->front )
        return 1;
    return 0;
}
