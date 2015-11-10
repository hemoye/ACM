#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81

typedef struct
{
    char data;
    struct BiTree * lchild, * rchild;
} BiTree, * BiNode;

BiNode Creat(char *, char *, int );
void print(BiNode );

int main(void)
{
    BiNode Tree;
    char first[MAX], among[MAX];

    scanf("%s%s", first, among);
    Tree = Creat(first, among, strlen(first));

    last_print(Tree);
    puts("");

    return 0;
}
BiNode Creat(char * first, char * among, int len)
{
    int k = 0;
    char * p;
    BiNode Tree = (BiNode)malloc(sizeof(BiTree));

    Tree->data = *first;

    if (len <= 0)
        return NULL;

    for (p = among; p; p++)
        if (*p == *first)
            break;

    k = p - among;

    Tree->lchild = Creat(first + 1, among, k);
    Tree->rchild = Creat(first + 1 + k, p + 1, len - 1 - k);

    return Tree;
}
void last_print(BiNode Tree)
{
    if (NULL == Tree)
        return ;

    last_print(Tree->lchild);
    last_print(Tree->rchild);
    printf("%c", Tree->data);

    return ;
}

