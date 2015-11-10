#include <iostream>
#define  MAXN 40

using namespace std;

struct Node {
    char data;
    Node * left;
    Node * right;
} ;

Node * Pre_Creat( void );
void Pre_Order( Node * );
void In_Order( Node * );
void Post_Order( Node * );
void Level_Traversal( Node * );
void Destory( Node * );

int main( void )
{
    Node * Root;

    cout << "Set a Tree by Preamble. " << endl;
    Root = Pre_Creat();
    cout << "Traversal a Tree by Preamble: ";
    Pre_Order( Root );
    cout << endl;
    cout << "Traversal a Tree by Inorder: ";
    In_Order( Root );
    cout << endl;
    cout << "Traversal a Tree by Postorde: ";
    Post_Order( Root );
    cout << endl;
    cout << "Traversal a Tree by Level: ";
    Level_Traversal( Root );
    cout << endl;
    Destory( Root );

    return 0;
}
Node * Pre_Creat( void )
{
    char ch;
    cin >> ch;
    if ( '#' == ch ){
        return NULL;
    }
    Node * T = new Node;
    T->data = ch;
    T->left = Pre_Creat();
    T->right = Pre_Creat();
    return T;
}
void Pre_Order( Node * T )
{
    if ( NULL != T ){
        cout << T->data << " ";
        Pre_Order( T->left );
        Pre_Order( T->right );
    }
    return ;
}
void In_Order( Node * T )
{
    if ( NULL != T ){
        In_Order( T->left );
        cout << T->data << " ";
        In_Order( T->right );
    }
    return ;
}
void Post_Order( Node * T )
{
    if ( NULL != T ){
        Post_Order( T->left );
        Post_Order( T->right );
        cout << T->data << " ";
    }
    return ;
}
void Level_Traversal( Node * T )
{
    Node * Queue[MAXN];
    int front(0), rear(0);

    Queue[rear++] = T;
    while ( front < rear ){
        Node * u = Queue[front++];
        cout << u->data << " ";
        if ( u->left ){
            Queue[rear++] = u->left;
        }
        if ( u->right ){
            Queue[rear++] = u->right;
        }
    }
    return ;
}
void Destory( Node * T )
{
    if ( NULL == T ){
        return ;
    }
    Destory( T->left );
    Destory( T->right );
    cout << T->data << " been delete." << endl;
    delete T;
    T = NULL;
}
