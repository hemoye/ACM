#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char data;
    struct BiTree * lchild;
    struct BiTree * rchild;
} BiTree, * BiTreePtr;

BiTreePtr Creat_BiTree( void );
void PreOrder( BiTreePtr );
void InOrder( BiTreePtr );
void PostOrder( BiTreePtr );

int main( void )
{
    BiTreePtr Tree = ( BiTreePtr )malloc( sizeof( BiTree ) );

    Tree = Creat_BiTree();

    PreOrder( Tree );
    puts("");
    InOrder( Tree );
    puts("");
    PostOrder( Tree );
    puts("");

    return ;
}
BiTreePtr Creat_BiTree( void )
{
    char ch;

    scanf("%c", &ch);

    if ( '#' == ch )
        return NULL;
    else
    {
        BiTreePtr Tree = ( BiTreePtr )malloc( sizeof( BiTree ) );

        Tree->data = ch;
        Tree->lchild = Creat_BiTree();
        Tree->rchild = Creat_BiTree();

        return Tree;
    }
}
/**********前序遍历二叉树**********/
void PreOrder( BiTreePtr T )
{
    if ( T == NULL )
        return ;

    printf("%c", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);

    return ;
}
/**********中序遍历二叉树**********/
void InOrder( BiTreePtr T )
{
    if ( T == NULL )
        return ;

    InOrder(T->lchild);
    printf("%c", T->data);
    InOrder(T->rchild);

    return ;
}
/**********后序遍历二叉树**********/
void PostOrder( BiTreePtr T )
{
    if ( T == NULL )
        return ;

    PostOrder(T->lchild);
    PostOrder(T->rchild);
    printf("%c", T->data);

    return ;
}
