#include <iostream>
#include <cstdio>

struct Node {
    char data;
    Node * Next;
} ;

Node * Set_Link( void );
void Traversal( Node * );
int  Search( Node * , char & );

int main( int agrc, char *agrv[] )
{
    char unknow;
    Node * Head;
    Head = Set_Link();

    printf("Please input the number of you want to search: ");
    scanf("%*c%c", &unknow );
    int pos = Search( Head, unknow );
    if ( pos ){
        printf("Yes, %c location at the link %d\n", unknow, pos );
    }
    else {
        printf("No, The link have not the element.");
    }

    return 0;
}
int Search( Node * Head, char &unkown )
{
    int pos(0);

    while ( Head->Next ){
        Head = Head->Next;
        pos++;
        if ( Head->data == unkown ){
            return pos;
        }
    }
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
