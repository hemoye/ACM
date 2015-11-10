#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node * Next;
} *NodePtr;

void Creat( NodePtr );
void Delete( NodePtr , int );
void Insert( NodePtr , int , int );
void Traverse( NodePtr );

int main( void )
{
    NodePtr Head = new Node;
    int m, n;

    Creat( Head );

    cin >> m;
    Delete( Head, m );

    cin >> m >> n;
    Insert( Head, m, n );

    Traverse( Head );

    return 0;
}
void Creat( NodePtr H )
{
    int n;
    NodePtr p1 = H;
    H->Next = NULL;

    cin >> n;

    for ( int i = 0; i < n; i++ )
    {
        NodePtr p2 = new Node;

        cin >> p2->data;
        p1->Next = p2;
        p1 = p2;
    }
    p1->Next = NULL;

    return ;
}
void Delete( NodePtr H, int x )
{
    while ( --x )
        H = H->Next;
    H->Next = H->Next->Next;

    return ;
}
void Insert( NodePtr H, int m, int n )
{
    while ( --m )
    {
        H = H->Next;
        if ( NULL == H )
            return ;
    }
    NodePtr p = new Node;
    p->data = n;
    p->Next = H->Next;
    H->Next = p;

    return ;
}
void Traverse( NodePtr H )
{
    while ( H->Next )
    {
        H = H->Next;
        cout << H->data << " ";
    }
    cout << endl;

    return ;
}
