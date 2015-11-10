#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct node * next;
} *nodep, node;

nodep Creat_link(nodep head, int );
int main(void)
{
    nodep head;

    head = Creat_link(&head, 5);
    while(head->next)
    {
        head = head->next;
        printf("%d ", head->data);
    }

    return 0;
}
nodep Creat_link(nodep head, int len)
{
    nodep p1, p2;
    head->next = NULL;
    p1 = head;
    while (len--)
    {
        p2 = (nodep)malloc(sizeof(node));
        scanf("%d", &p2->data);
        p1->next = p2;
        p2->next = NULL;
        p1 = p2;
    }
    return head;
}
