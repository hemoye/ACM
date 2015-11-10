#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node * next;
} Node, * pNode;
typedef struct
{
    pNode Top;
    pNode Bottom;
} Stack, * pStack;

void init(pStack);
void push(pStack, int);
void detele(pStack);
void traverse(pStack);
void clear(pStack);

int main(void)
{
    pNode S;//记住！这里是定义一个链表节点！

    init(&S);

    push(&S, 4);
    push(&S, 9);
    push(&S, 9);
    push(&S, 1);

    traverse(&S);
    putchar('\n');

    detele(&S);
    traverse(&S);
    putchar('\n');

    clear(&S);
    traverse(&S);
    putchar('\n');

    return 0;
}
void init(pStack pS)
{
    pS->Top = (pNode)malloc(sizeof(Node));//一定要记住、这里是对栈顶的指向分配空间。而不是为栈顶分配空间！
    pS->Bottom = pS->Top;
    pS->Top->next = NULL;
}
void push(pStack pS, int val)
{
    pNode New = (pNode)malloc(sizeof(Node));
    New->data = val;
    New->next = pS->Top;
    pS->Top = New;
}
void detele(pStack pS)
{
    pNode New = pS->Top;
    pS->Top = New->next;
    free(New);
}
void traverse(pStack pS)
{
    pNode p = pS->Top;
    while(p != pS->Bottom)
    {
        printf("%d", p->data);
        p = p->next;
    }
}
void clear(pStack pS)
{
    pNode p = pS->Top;
    pNode q = NULL;
    while(p != pS->Bottom)
    {
        q = p->next;
        free(p);
        p = q;
    }
    pS->Top = pS->Bottom;
}
