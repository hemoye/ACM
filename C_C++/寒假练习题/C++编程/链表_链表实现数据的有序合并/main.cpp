#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node * Next;
} *NodePtr;

void Creat( NodePtr , int );
void Merge( NodePtr , NodePtr );
void Sort( NodePtr H, int x );
void Traverse( NodePtr );

int main( void )
{
    int m, n;

    NodePtr Head1 = new Node;
    NodePtr Head2 = new Node;

    while ( cout << "请输入A表的表长 ：" && cin >> m && m )
    {
        Creat( Head1, m );
        cout << "请输入B表的表长 ：";
        cin >> n;
        Creat( Head2, n );

        Merge( Head1, Head2 );
        delete Head2;
        Sort( Head1, m+n );

        Traverse( Head1 );
        delete Head1;
    }

    return 0;
}
void Creat( NodePtr H, int n )
{
    NodePtr p1 = H;
    H->Next = NULL;

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
void Traverse( NodePtr H )
{
    cout << endl << "MergeList_L(A, B, C); List C = ( ";

    while ( H->Next )
    {
        H = H->Next;
        cout << H->data << " ";
    }
    cout << ")" << endl << endl;

    return ;
}
