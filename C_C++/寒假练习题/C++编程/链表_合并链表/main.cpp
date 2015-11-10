#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node * Next;
}  * NodePtr;

NodePtr Creat( int m );
void Merge( NodePtr , NodePtr );
void Traverse( NodePtr );
void Sort( NodePtr , int );

int main( void )
{
    int m, n;

    NodePtr Head1 = new Node;
    NodePtr Head2 = new Node;

    cin >> m;
    Head1 = Creat( m );
    cin >> n;
    Head2 = Creat( n );

    Merge( Head1, Head2 );
    delete Head2;
    Sort( Head1, m );
    Traverse( Head1 );

    return 0;
}
NodePtr Creat( int m )
{
    NodePtr Head = new Node;
    NodePtr p = Head;

    Head->Next = NULL;
    for ( int i = 0; i < m; i++ )
    {
        NodePtr q = new Node;

        cin >> q->data;
        p->Next = q;
        p = q;
    }
    p->Next = NULL;

    return Head;
}
void Merge( NodePtr H1, NodePtr H2 )
{
    while ( H1->Next )
        H1 = H1->Next;

    H1->Next = H2->Next;

    return ;
}
void Sort( NodePtr H, int x )
{
    NodePtr p, temp;

    while ( --x )
        for ( p = H; p->Next->Next; p = p->Next )
            if ( p->Next->data > p->Next->Next->data )
            {
                temp = p->Next->Next;
                p->Next->Next = temp->Next;
                temp->Next = p->Next;
                p->Next = temp;
            }

    return ;
}
void Traverse( NodePtr Head )
{
    while ( Head->Next )
    {
        Head = Head->Next;
        cout << Head->data << " ";
    }
    cout << endl;

    return ;
}
