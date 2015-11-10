#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 40

typedef struct
{
    int data[MAXSIZE];
    int top;
} Stack;

void push( Stack * , int  );
void init( Stack * );
void Traverse( Stack * stud );
int pop( Stack * stud );

int main( void )
{
    Stack stud;
    int n, temp, time;

    init( &stud );

    scanf("%d", &time);
    while ( time-- )
    {
        scanf("%d", &n);
        push( &stud, n );
    }
    printf("������ջ�õ�Ԫ�أ�");
    Traverse( &stud );

    while ( time++ < 3 )
        if ( temp = pop( &stud ) )
            printf("��ջ�ɹ����˴γ�ջ��Ԫ����:%d\n", temp );
        else
            printf("��ջʧ��!\n");
    printf("������ջ�õ�Ԫ�أ�");
    Traverse( &stud );

    return 0;
}
void init( Stack * S )
{
    S->top = 0;
    return ;
}
void push( Stack * stud, int n )
{
    if ( MAXSIZE == stud->top )
    {
        printf("ջ�������˴β���ʧ�ܣ�\n");
        getch();
        return ;
    }

    stud->data[stud->top] = n;
    stud->top++;

    return ;
}
void Traverse( Stack * stud )
{
    int x = stud->top - 1;

    if ( x < 0 )
        printf("����ʧ�ܣ���ջΪ��ջ.\n");

    while ( x >= 0 )
    {
        printf("%d ", stud->data[x]);
        x--;
    }
    puts("");

    return ;
}
int pop( Stack * stud )
{
    int x;

    if ( stud->top == 0 )
    {
        printf("��ջʧ�ܣ���ջΪ��ջ��\n");
        getch();
        return 0;
    }


    x = stud->data[--stud->top];

    return x;
}
