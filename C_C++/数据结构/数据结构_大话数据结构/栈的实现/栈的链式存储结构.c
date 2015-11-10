#include <stdio.h>
#include <stdlib.h>

typedef struct//��������Ԫ�صĽṹ��
{
    int data;
    struct StackNode * Next;
} StackNode, *LikeNode;

typedef struct//ջ��ָ��
{
    LikeNode Top;
    int count;
} LikeStack;

void push( LikeNode );
void Traverse( LikeNode );
int  pop( LikeNode );

LikeStack * ptr;

int main( void )
{
    LikeNode S = ( LikeNode )malloc( sizeof( StackNode ) );
    ptr = ( LikeStack * )malloc( sizeof( LikeStack ) );
    ptr->count = 0;
    int x, a = 5;

    push( &S );
    printf("������ջ���£�\n");
    Traverse( &S );
    puts("");
    while ( a-- )
        if ( x = pop( &S ) )
            printf("�˴γ�ջ��Ԫ���ǣ�%d\n", x );
        else
            printf("��ջʧ�ܣ���ջΪ��ջ!\n");

    printf("������ջ���£�\n");
    Traverse( &S );
    puts("");

    return 0;
}
void push( LikeNode S )
{
    int n;

    while ( 1 )
    {
        printf("Please enter a number(end of 0):");
        scanf("%d", &n);
        if ( 0 == n )
            break;

        LikeNode temp = ( LikeNode )malloc( sizeof( StackNode ) );
        ptr->count++;//ջ�ĳ��ȼ�һ
        temp->data = n;//����ջ��Ԫ�ص�ֵ
        temp->Next = ptr->Top;//��ջ��Ԫ��ָ��ԭջ��Ԫ��
        ptr->Top = temp;//ջָ��ָ����ջ��Ԫ��
    }

    return ;
}
void Traverse( LikeNode S )
{
    int x = ptr->count;
    LikeNode temp = S;
    temp->Next = ptr->Top;

    if ( x == 0 )
    {
        printf("����ʧ�ܣ���ջΪ��ջ��\n");
        getch();
        return ;
    }

    while ( x-- > 0 )
    {
        temp = temp->Next;
        printf("%d ", temp->data);
    }
    return ;
}
int pop( LikeNode S )
{
    int x;
    LikeNode temp;

    if ( ptr->count == 0 )
        return 0;

    temp = ptr->Top;
    x = temp->data;
    ptr->Top = temp->Next;
    ptr->count--;
    free( temp );

    return x;
}
