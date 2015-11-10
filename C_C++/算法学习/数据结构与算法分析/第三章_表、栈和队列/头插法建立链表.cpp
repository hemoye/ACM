#include <iostream>

using namespace std;

struct Node {
    char data;
    Node * Next;
} ;

Node * Creat( void );
void Traversal( Node * );

int main( void )
{
    Node * Root = Creat();
    Traversal( Root );

    return 0;
}
Node * Creat( void )
{
    Node * Root = new Node;
    Node * p = Root;
    char ch;

    while ( true ){
        cin >> ch;
        if ( '#' == ch ){
            break;
        }
        Node * q = new Node;
        q->data = ch;
        p->Next = q;
        p = q;
    }
    p->Next = NULL;

    return Root;
}
void Traversal( Node * R )
{
    while ( R->Next ){
        R = R->Next;
        cout << R->data << " ";
    }
    cout << endl;
    return ;
}
