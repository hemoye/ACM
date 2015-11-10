#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char data;
    struct Node * Next;
    struct Node * Pre;
} Node, * pNode;

void Creat( pNode );
void Traverse( pNode );
char Delete( pNode , int );

int main( void )
{
    pNode Head = ( pNode ) malloc ( sizeof( Node ) );
    char ch;
    int n;

    Creat( Head );
    Traverse( Head );

    printf("Please enter a number what your want to delete : ");
    scanf("%d", &n );
    ch = Delete( Head, n );
    if ( '0' == ch )
        printf("Sorry, the list just not %d length.\n", n );
    else
        printf("Just now, you delete a char what is %c.\n", ch );
    Traverse( Head );

    return 0;
}
void Creat( pNode Head )
{
    char ch;
    pNode p1 = Head;

    while ( 1 )
    {
        printf("Please enter a char(By end of '#'): ");
        scanf(" %c", &ch );

        if ( '#' == ch )
            break;

        pNode p2 = ( pNode ) malloc ( sizeof ( Node ) );

        p1->Next = p2;
        p2->data = ch;
        p2->Pre = p1;
        p1 = p2;
    }
    p1->Next = NULL;

    return ;
}
void Traverse( pNode H )
{
    if ( H == NULL )
        return ;
    while ( H->Next )
    {
        H = H->Next;
        printf("%c ", H->data);
    }
    puts("");

    return ;
}
char Delete( pNode H, int n )
{
    pNode p = H;
    char ch;
    int i;

    for ( i = 0; i < n; i++ )
        if ( p->Next )
            p = p->Next;
        else
            return '0';

    pNode temp1, temp2;

    temp1 = p->Pre;
    temp2 = p->Next;

    ch = p->data;
    temp1->Next = p->Next;
    temp2->Pre = p->Pre;
    free( p );

    return ch;
}
