#include <iostream>
#include <cstdio>

struct Node {
    char data;
    Node * Next;
} ;

Node * Set_Link( void );
void Traversal( Node * );
char Delete( Node * , int & );

int main( int argc, char *agrv[] )
{
    Node * Head;
    int  location;

    Head = Set_Link();
    printf("Please input the element location of you want to delete: ");
    scanf("%d", &location );
    char element = Delete( Head, location );
    if ( '0' != element ){
        printf("The %c was delete.\n", element );
    }
    else {
        printf("Delete failed, the link is too short.");
    }
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
char Delete( Node * Head, int &location )
{
    for ( int i = 1; i < location; i++ ){
        Head = Head->Next;
        if ( NULL == Head ){
            return '0';
        }
    }
    Node * temp = Head->Next;
    char x = temp->data;
    Head->Next = temp->Next;
    delete temp;

    return x;
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
