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
void Traverse( LinkQueue * );          //��������������
int  QueueLength( LinkQueue * );       //������������г���
int  Judge( LinkQueue * );             //�������ж϶����Ƿ�����

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
        printf("����ʧ�ܣ��ö���Ϊ�ն��У�\n");
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
        printf("����ʧ�ܣ��ö���Ϊ�ն��У�\n");
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

