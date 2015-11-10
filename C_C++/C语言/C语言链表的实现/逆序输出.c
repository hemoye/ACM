#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * nixu(struct Node *);

int main(void)
{
    int len = 5;
    struct Node * head, * p1, * p2;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    p1 = head;

    while(len--)
    {
        p2 = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &p2->data);
        p1->next = p2;
        p2->next = NULL;
        p1 = p2;
    }
    head = nixu(head);
    p1 = head;
    while(p1->next)
    {
        p1 = p1->next;
        printf("%d ", p1->data);
    }

    return 0;
}
struct Node * nixu(struct Node * head)
{
    int flage = 1;
    struct Node * New_head, * p1, * p2;
    New_head = (struct Node *)malloc(sizeof(struct Node));
    while(head->next->next)
    {
        for (p1 = head; p1->next->next; p1 = p1->next);
        p2 = p1->next;//p2得到p1的下一个节点
        p1->next = NULL;//将原链表的倒数第二个有效节点放空
        p2->next = p1;//使尾节点指向下一个节点
        if (flage)
        {
            New_head->next = p2;//将原链表最后一个节点接到新表头后面
            flage = 0;
        }
        if (head == p1)//当到了第一个节点之后放空p1,将p2的指针域指向空节点
        {
            free(p1);
            p2->next = NULL;
        }
    }
    return New_head;
}
