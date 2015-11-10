#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node * next;
} * Nodep, Node;

Nodep Creat(Nodep );
int main(void)
{
    Nodep head;

    head = Creat(head);
    while(head->next)
    {
        head = head->next;
        printf("%d\n", head->data);
    }

    return 0;
}
Nodep Creat(Nodep head)
{
    int len = 5;
    Nodep p1, p2;
    head = (Nodep)malloc(sizeof(Node));//分配一个头节点
    p1 = head;
    while(len--)
    {
        p2 = (Nodep)malloc(sizeof(Node));
        scanf("%d", &p2->data);
        p1->next = p2;//将p2接到最后一个节点后面
        p2->next = NULL;//放空p2的指向
        p1 = p2;//此语句的集体含义：将p1每一次都重置为最后一个节点
    }

    return head;
}
