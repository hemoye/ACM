#include <iostream>
#include <cstring>
const int MAXN = 40;

struct Node
{
    char data;
    Node * left;
    Node * right;
} ;

using namespace std;

Node * Creat( int n, char * , char * );
void Postprintf( Node * );

int main( void )
{
    char str1[MAXN], str2[MAXN];
    Node * Tree;

    cin >> str1 >> str2;

    Tree = Creat(  strlen( str1 ), str1, str2 );
    Postprintf( Tree );

    return 0;
}
Node * Creat( int n, char * str1, char * str2 )
{
    if ( n <= 0 )
        return NULL;

    Node * T = new Node;
    int p = 0;

    for ( ; str2[p] != str1[0]; p++ );

    T->data = str1[0];
    T->left = ( p, str1 + 1, str2 );
    T->right = ( n - 1 - p, str1 + 1 + p, str2 + p + 1 );

    return T;
}
void Postprintf( Node * T )
{
    if ( NULL == T )
        return ;
    Postprintf( T->left );
    Postprintf( T->right );
    cout << T->data;

    return ;
}
