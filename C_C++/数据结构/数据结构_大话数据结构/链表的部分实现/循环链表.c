#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char data;
    struct Node * Next;
} Node, *pNode;

pNode Creat_List( void );
void  Traverse( pNode );

int main( void )
{
    pNode Head;

    Head = Creat_List();
    Traverse( Head );

    return 0;
}
pNode Creat_List( void )
{
    pNode Head = ( pNode ) malloc ( sizeof( Node ) );
    pNode p1;

    p1 = Head;
    Head->Next = NULL;

    while ( 1 )
    {
        pNode p2 = ( pNode ) malloc ( sizeof( Node ) );

        scanf("%c", &p2->data);
        if ( '#' == p2->data )
            break;
        p1->Next = p2;
        p1 = p2;
    }
    p1->Next = Head->Next;

    return Head;
}
void Traverse( pNode Head )
{
    int count = 0;

    while ( Head->Next )
    {
        Head = Head->Next;
        printf("%c", Head->data);
        count++;

        if ( 0 == count % 5 )
            puts("");

        if ( count > 19 )
            break;
    }

    return 0;
}
