#include <stdio.h>
#include <stdlib.h>

typedef struct//构建储存元素的结构体
{
    int data;
    struct StackNode * Next;
} StackNode, *LikeNode;

typedef struct//栈顶指针
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
    printf("遍历该栈如下：\n");
    Traverse( &S );
    puts("");
    while ( a-- )
        if ( x = pop( &S ) )
            printf("此次出栈的元素是：%d\n", x );
        else
            printf("出栈失败！此栈为空栈!\n");

    printf("遍历该栈如下：\n");
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
        ptr->count++;//栈的长度加一
        temp->data = n;//输入栈顶元素的值
        temp->Next = ptr->Top;//新栈顶元素指向原栈顶元素
        ptr->Top = temp;//栈指针指向新栈顶元素
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
        printf("遍历失败！此栈为空栈！\n");
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
