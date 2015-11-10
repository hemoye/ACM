#include <iostream>

const int MAXN = 40;

struct Node
{
    char data;
    Node * left;
    Node * right;
} ;

Node * Creat( void );
void Fristprintf( Node * );
void Amongprintf( Node * );
void Lastprintf( Node * );
void bfs( Node * );

int main( void )
{
    Node * Head = new Node;

    Head = Creat();
    std::cout << "层序遍历：";
    bfs( Head );
    std::cout << "先序遍历：";
    Fristprintf( Head );
    std::cout << std::endl;
    std::cout << "中序遍历：";
    Amongprintf( Head );
    std::cout << std::endl;
    std::cout << "后序遍历：";
    Lastprintf( Head );
    std::cout << std::endl;

    delete Head;

    return 0;
}
Node * Creat( void )
{
    char ch;

    std::cin >> ch;

    Node * NewNode = new Node;

    if ( '#' == ch )
        return NULL;

    NewNode->data = ch;
    NewNode->left = Creat();
    NewNode->right = Creat();
    return NewNode;
}
void Fristprintf( Node * T )
{
    if ( NULL == T )
        return ;
    std::cout << T->data;
    Fristprintf( T->left );
    Fristprintf( T->right );

    return ;
}
void Amongprintf( Node * T )
{
    if ( NULL == T )
        return ;
    Amongprintf( T->left );
    std::cout << T->data;
    Amongprintf( T->right );

    return ;
}
void Lastprintf( Node * T )
{
    if ( NULL == T )
        return ;
    Lastprintf( T->left );
    Lastprintf( T->right );
    std::cout << T->data;

    return ;
}
void bfs( Node * T )
{
    Node * q[MAXN];
    int front = 0, rear = 1;

    q[0] = T;
    while ( front < rear )
    {
        Node * temp = q[front++];

        if ( temp->left )
            q[rear++] = temp->left;
        if ( temp->right )
            q[rear++] = temp->right;
    }
    for ( int i = 0; i < rear; i++ )
        std::cout << q[i]->data;
    std::cout << std::endl;

    return ;
}
