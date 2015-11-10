#include <iostream>
#include <cstdio>

struct Node {
    char data;
    Node * left;
    Node * right;
} ;

Node * Pre_creat_tree( void );
Node * Find_information( Node * , char & );

int main( int argc, int *argv[] )
{
    Node * Root;
    char information;

    printf("Set a Tree by preamble.\n");
    Root = Pre_creat_tree();
    printf("Please enter the information tha you want to find: ");
    scanf(" %c", &information );
    if ( Find_information( Root, information ) ){
        printf("Yes, information in the tree inside.\n");
    }
    else {
        printf("No, information was not in the tree inside.\n");
    }

    return 0;
}
Node * Pre_creat_tree( void )
{
    char ch;
    scanf("%c", &ch );

    if ( '#' == ch ){
        return NULL;
    }
    else {
        Node * T = new Node;
        T->data = ch;
        T->left = Pre_creat_tree();
        T->right = Pre_creat_tree();
        return T;
    }
}
Node * Find_information( Node * T, char & mark )
{
    if ( NULL == T ){
        return NULL;
    }
    else {
        if ( T->data == mark ){
            return T;
        }
        else {
            Node * p = Find_information( T->left, mark );
            if ( p ){
                return p;
            }
            else {
                return Find_information( T->right, mark )
;            }
        }
    }
}
