#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node * next;
} Node, * pNode;

pNode nixu(pNode);

int main(void)
{
    int i;
    pNode head, p1, p2;

    head = (pNode)malloc(sizeof(Node));
    head->next = NULL;
    p1 = head;

    for(i = 0; i < 5; i++)
    {
        p2 = (pNode)malloc(sizeof(Node));
        scanf("%d", &p2->data);
        p1->next = p2;
        p2->next = NULL;
        p1 = p2;
    }
    head = nixu(head);
    p1 = head;
    while(NULL != p1->next)
    {
        p1 = p1->next;
        printf("%d ", p1->data);
    }

    return 0;
}
pNode nixu(pNode head)
{
    int flage = 1;
    pNode new_head, p1, p2;
    new_head = (pNode)malloc(sizeof(Node));
    head = head->next;
    while(head->next)
    {
        for(p1 = head->next; p1->next; p1 = p1->next);
        p2 = p1->next;
        p1->next = NULL;
        p2->next = p1;
        if (flage)
        {
            new_head = p2;
            flage = 0;
        }
        if (head == p1)
        {
            free(p1);
            p2->next = NULL;
        }
    }
    return new_head;
}
