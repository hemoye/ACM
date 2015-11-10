#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node * Next;
} Node, * pNode;

typedef struct //����һ��ջ
{
    pNode Top;
    pNode Bottom;
} Stack, * pStack;

void init(pStack );
void push(pStack , int );
void traverse(pStack );

int main(void)
{
    pNode S;
    int number;

    scanf("%d", &number);

    init(&S);
    while (number)
    {
        push(&S, number % 8);
        number /= 8;
    }

    traverse(&S);
    puts("");

    return 0;
}
void init(pStack pS)
{
    pS->Top = (pNode)malloc(sizeof(Node));
    pS->Bottom = pS->Top;
    pS->Top->Next = NULL;
}
void push(pStack pS, int val)
{
    pNode New = (pNode)malloc(sizeof(Node));

    New->data = val;
    New->Next = pS->Top;
    pS->Top = New;
}
void traverse(pStack pS)
{
    pNode p = pS->Top;

    while (p != pS->Bottom)
    {
        printf("%d", p->data);
        p = p->Next;
    }
}
