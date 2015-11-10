#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 401

typedef struct
{
    char data;
    struct BiNode * lchild;
    struct BiNode * rchild;
} BiNode, * BiTree;

BiTree Creat(char *, char *, int );
void print(BiTree );

int main(void)
{
    char first[MAX], middle[MAX];

    while (scanf("%s%s", first, middle) != EOF)
    {
        BiTree Tree = (BiTree)malloc(sizeof(BiNode));

        Tree = Creat(first, middle, strlen(first));
        print(Tree);
        puts("");
    }

    return 0;
}
BiTree Creat(char * first, char * middle, int len)
{
    BiTree Tree = (BiTree)malloc(sizeof(BiNode));
    char * p;
    int k = 0;

    Tree->data = *first;

    if (len <= 0)
        return NULL;

    for (p = middle; p; p++)
        if (*p == *first)
            break;

    k = p - middle;

    Tree->lchild = Creat(first + 1, middle, k);
    Tree->rchild = Creat(first + 1 + k, p + 1, len - 1 - k);

    return Tree;
}
void print(BiTree Tree)
{
    if (NULL == Tree)
        return ;

    print(Tree->lchild);
    print(Tree->rchild);
    printf("%c", Tree->data);

    return ;
}
