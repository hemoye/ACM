#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
};

int main(void)
{
    int len = 9, time = 0;
    struct Node * h, * p1, * p2, * temp;

    h = (struct Node *)malloc(sizeof(struct Node));
    h->next = NULL;
    p1 = h;

    while (len--)
    {
        p2 = (struct Node *)malloc(sizeof(struct Node ));
        scanf ("%d", &p2->data);
        p1->next = p2;
        p2->next = NULL;
        p1 = p2;
    }
    for (p1 = h; p1->next; p1 = p1->next)
        for (p2 = h; p2->next->next; p2 = p2->next)
            if (p2->next->data > p2->next->next->data)
            {
                temp = p2->next->next;
                p2->next->next = temp->next;
                temp->next = p2->next;
                p2->next = temp;
            }

    while (h->next)
    {
        h = h->next;
        if (h->data == len)
            continue;
        time++;
        printf((time == 1) ? "%d" : " %d", h->data);
        len = h->data;
    }

    return 0;
}
