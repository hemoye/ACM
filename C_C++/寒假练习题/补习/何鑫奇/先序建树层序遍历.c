#include <stdio.h>
#include <stdlib.h>
#define  MAXN 1000

typedef struct
{
    char data;
    struct BiTree * left;
    struct BiTree * right;
} BiTree, * BiTreePtr;

BiTreePtr Creat_Tree( void );
void print_Tree( BiTreePtr );

int main( void )
{
    BiTreePtr Tree;

    Tree = Creat_Tree();
    print_Tree( Tree );

    return 0;
}
BiTreePtr Creat_Tree( void )
{
    char ch;
    scanf("%c", &ch );

    if ( '#' == ch )
        return NULL;

    BiTreePtr New_Tree = ( BiTreePtr ) malloc ( sizeof( BiTree ) );

    New_Tree->data = ch;
    New_Tree->left = Creat_Tree();
    New_Tree->right = Creat_Tree();
}
void print_Tree( BiTreePtr T )
{
    if ( NULL == T )
        return ;
    int front = 0, rear = 0;
    BiTreePtr Q[MAXN];

    Q[rear++] = T;
    while ( front < rear )
    {
        BiTreePtr temp = Q[front++];
        printf("%c", temp->data);

        if ( temp->left != NULL )
            Q[rear++] = temp->left;
        if ( temp->right != NULL )
            Q[rear++] = temp->right;
        free( temp );
    }

}
