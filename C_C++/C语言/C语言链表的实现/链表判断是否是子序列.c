#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node * Next;
} Node, *pNode;

pNode Creat(int );

int main(void)
{
    pNode Head1, Head2, p, q;
    int n, count = 0;

    scanf("%d", &n);
    Head1 = Creat(n);

    scanf("%d", &n);
    Head2 = Creat(n);

    for (p = Head2->Next; p; p = p->Next)
        for (q = Head1->Next; q; q = q->Next)
            if (p->data == q->data)
            {
                count++;
                break;
            }
    printf((n == count) ? "1\n" : "0\n");

    return 0;
}
pNode Creat(int n)
{
    pNode Head, p1, p2;

    Head = (pNode)malloc(sizeof(Node));
    p1 = Head;

    while ( n-- )
    {
        p2 = (pNode)malloc(sizeof(Node));
        scanf("%d", &p2->data);
        p1->Next = p2;
        p1 = p2;
    }
    p1->Next = NULL;

    return Head;
}
