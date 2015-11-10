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

void Init( LinkQueue * );              //����:��ʼ������
void EnQueue( LinkQueue * );           //���������
void  DeQueue( LinkQueue * );           //����������
void Traverse( LinkQueue * );          //��������������
int  QueueLength( LinkQueue * );       //������������г���
int  Judge( LinkQueue * );             //�������ж϶����Ƿ�����

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
void DeQueue( LinkQueue * Q )
{
    QNodePtr temp;
    char str[MAXSIZE];

    if ( Q->rear == Q->front )
    {
        printf("����ʧ�ܣ��ö���Ϊ�ն��У�\n");
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

