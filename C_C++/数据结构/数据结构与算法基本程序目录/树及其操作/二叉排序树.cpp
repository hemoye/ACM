#include <iostream>
#include <cstring>
#include <cstdio>
#define  MAXN_SIZE

struct Node {
    int data;
    Node * left;
    Node * right;
} ;

Node * Set_Tree( void );
void In_Order( Node * );

int main( int agrc, char * agrv[] )
{
    Node * Root;

    printf("Set a binary sort tree£º");
    Root = Set_Tree();
    printf("Inorder as follow: ");
    In_Order( Root );
    puts("");

    return 0;
}
Node * Set_Tree( void )
{
    int n, x;
    Node * Root = new Node;

    printf("Please enter the size of the array: " );
    scanf("%d", &n );
    printf("Please enter the n elements£º");
    for ( int i = 0; i < n; i++ ){
        scanf("%d", &x );
        if ( 0 == i ){
            Root->data = x;
            Root->left = Root->right = NULL;
        }
        else {
            Node * temp = Root;
            Node * p = new Node;
            p->data = x;
            p->left = p->right = NULL;
            while ( temp ) {
                if ( temp->data > x ){
                    if ( NULL == temp->right ){
                        temp->right = p;
                        break;
                    }
                    else {
                        temp = temp->right;
                    }
                }
                else if ( temp->data < x ){
                    if ( NULL == temp->left  ){
                        temp->left = p;
                        break;
                    }
                    else {
                        temp = temp->left;
                    }
                }
                else if ( temp->data == x ) {
                    delete p;
                    printf("This element has been sort tree.\n");
                    break;
                }
            }
        }
    }
    return Root;
}
void In_Order( Node * Root )
{
    if ( NULL == Root ){
        return ;
    }
    else {
        In_Order( Root->left );
        printf("%d ", Root->data );
        In_Order( Root->right );
    }
}
