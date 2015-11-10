/**问题转化：
    得到后缀表达式之后，就是后序建树
**/
#include <iostream>
#include <stack>

using namespace std;

struct Node {
    char data;
    Node * left;
    Node * right;
    Node ( char c ): data( c ), left( NULL ), right( NULL ){};
} ;

Node * Creat_ET( char * );
void PostOrder( Node * );
void PreOrder( Node * );

int main( void )
{
    Node * Root = Creat_ET( "ab+cde+**");
    PostOrder( Root );
    cout << endl;
    PreOrder( Root );
    cout << endl;

    return 0;
}
void PostOrder( Node * T )
{
    if ( NULL == T ){
        return ;
    }
    else {
        PostOrder( T->left );
        PostOrder( T->right );
        cout << T->data << " ";
    }
}
void PreOrder( Node * T )
{
    if ( NULL == T ){
        return ;
    }
    else {
        cout << T->data << " ";
        PreOrder( T->left );
        PreOrder( T->right );
    }
}
Node * Creat_ET( char * src )
{
    stack<Node*> st;
    char * s = src;
    Node * temp;

    while ( *s ){
        if ( '+' == *s || '-' == *s || '*' == *s || '/' == *s ){
            temp = new Node( *s );
            temp->right = st.top();
            st.pop();
            temp->left = st.top();
            st.pop();
            st.push( temp );
        }
        else {
            temp = new Node( *s );
            st.push( temp );
        }
        s++;
    }
    return st.top();
}
