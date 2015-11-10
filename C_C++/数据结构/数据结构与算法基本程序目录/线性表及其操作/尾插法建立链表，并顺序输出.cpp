#include <iostream>
#include <cstdio>

struct Node {
    char data;
    Node * Next;
} ;

Node * Set_Link( void );
void Traversal( Node * );

int main( int argc, char *agrv[] )
{
    Node * Head;

    Head = Set_Link();
    Traversal( Head );

    return 0;
}
Node * Set_Link( void )
{
    int n;
    Node * Head = new Node;
    Node * p = Head;
    Head->Next = NULL;

    printf("Please enter the size of the link: ");
    scanf("%d%*c", &n );
    printf("Please enter the n elements: ");
    for ( int i = 0; i < n; i++ ){
        Node * q = new Node;
        scanf(" %c", &q->data );
        p->Next = q;
        p = q;
    }
    p->Next = NULL;

    return Head;
}
void Traversal( Node * Head )
{
    while ( Head->Next ){
        Head = Head->Next;
        printf("%c ", Head->data );
    }
    puts("");
    return ;
}
