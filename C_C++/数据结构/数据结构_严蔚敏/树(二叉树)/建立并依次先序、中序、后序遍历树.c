#include <stdio.h>
#include <stdlib.h>
#define MAX 401

typedef struct
{
    char data;
    struct BiTree * lchild;
    struct BiTree * rchild;
} BiTree, * BiNode;

BiNode Creat(void);
void first_print(BiNode);
void among_print(BiNode);
void last_print(BiNode);

int main(void)
{
    int n;

    scanf("%d", &n);

    while ( n-- )
    {
        getchar();

        BiNode Tree = (BiNode)malloc(sizeof(BiTree));
        Tree = Creat();

        first_print(Tree);
        puts("");
        among_print(Tree);
        puts("");
        last_print(Tree);
        puts("");

        free(Tree);
    }

    return 0;
}
BiNode Creat(void)//按照先序的遍历方式建立一棵树
{
    char ch;
    scanf("%c", &ch);

    if ('-' == ch)
        return NULL;
    else
    {
        BiNode Tree = (BiNode)malloc(sizeof(BiTree));

        Tree->data = ch;
        Tree->lchild = Creat();
        Tree->rchild = Creat();

        return Tree;
    }
}
void first_print(BiNode Tree)//先序遍历
{
    if (NULL == Tree)
        return ;

    printf("%c", Tree->data);
    first_print(Tree->lchild);
    first_print(Tree->rchild);

    return ;
}
void among_print(BiNode Tree)//中序遍历
{
    if (NULL == Tree)
        return ;

    among_print(Tree->lchild);
    printf("%c", Tree->data);
    among_print(Tree->rchild);

    return ;
}
void last_print(BiNode Tree)//后序遍历
{
    if (NULL == Tree)
        return ;

    last_print(Tree->lchild);
    last_print(Tree->rchild);
    printf("%c", Tree->data);

    return ;
}
