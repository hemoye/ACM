#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 5

/******�������нṹ��*******/
typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
} Queue;

void Init( Queue * );        //����:��ʼ������
void EnQueue( Queue * );     //���������
int  DeQueue( Queue * );     //����������
void Traverse( Queue * );    //��������������
int  QueueLength( Queue * ); //������������г���
int  Judge( Queue * );       //�������ж϶����Ƿ�����

/************������************/
int main( void )
{
    Queue Q;

    Init( &Q );
    EnQueue( &Q );

    printf("�˶��еĳ���Ϊ:%d\n", QueueLength( &Q ));
    printf("�����˶�������Ԫ������:\n");
    Traverse( &Q );
    puts("");

    if ( Judge( &Q ) )
        printf("����ʧ�ܣ�����Ϊ�գ�\n");
    else
        printf("�˴γ��ӵ�Ԫ��Ϊ:%d\n", DeQueue( &Q ));

    printf("�˶��еĳ���Ϊ:%d\n", QueueLength( &Q ));
    printf("�����˶�������Ԫ������:\n");
    Traverse( &Q );
    puts("");

    return 0;
}
/************��ʼ������************/
void Init( Queue * Q )
{
    Q->front = Q->rear = 0;

    return ;
}
/************��Ӻ���************/
void EnQueue( Queue * Q )
{
    int n;

    while ( 1 )
    {
        scanf("%d", &n);

        if ( 0 == n )
            break;

        if ( ( Q->rear + 1 ) % MAXSIZE == Q->front )
        {
            printf("�˴β���ʧ�ܣ�����������\n");
            getch();
            return ;
        }

        Q->data[Q->rear] = n;
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
    int temp = Q->front;

    if ( temp == Q->rear )
    {
        printf("����ʧ�ܣ��˶���Ϊ�ն���!\n");
        getch();
        return ;
    }
    Q->front = ( Q->front + 1 ) % MAXSIZE;

    return Q->data[temp];
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
