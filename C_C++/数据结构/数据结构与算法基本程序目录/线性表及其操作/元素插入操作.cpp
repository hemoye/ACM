#include <iostream>
#include <cstdio>

struct Node {
    char data;
    Node * Next;
} ;

Node * Set_Link( void );
void Insert( Node * , int & );
void Traversal( Node * );

int main( int argc, char *agrv[] )
{
    Node * Head;
    int location;

    Head = Set_Link();
    printf("Please input the location(after the number) where you want to insert: ");
    scanf("%d", &location );
    Insert( Head, location );
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
void Insert( Node * Head, int & location )
{
    for ( int i = 0; i < location; i++ ){
        Head = Head->Next;
        if ( NULL == Head ){
            printf("Sorry, The link is too short, failed insert.\n");
            return ;
        }
    }
    Node * New = new Node;
    printf("Please input the element of you want insert: ");
    scanf(" %c", &New->data );
    New->Next = Head->Next;
    Head->Next = New;

    return ;
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
