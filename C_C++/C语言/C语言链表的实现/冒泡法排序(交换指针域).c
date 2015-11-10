#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node * next;
};
void Quick(struct Node *);
int main(void)
{
    int len = 6;
    struct Node * head, * p1, * p2;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    p1 = head;

    while (len--)
    {
        p2 = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &p2->data);
        p1->next = p2;
        p2->next = NULL;
        p1 = p2;
    }
    Quick(head);
    while(head->next)
    {
        head = head->next;
        printf("%d ", head->data);
    }

    return 0;
}
void Quick(struct Node * head)
{
    int i = 2;
    struct Node * p1, * p2, * temp;
    while (i--)
        for (p1 = head; p1->next; p1 = p1->next)
            for (p2 = p1; p2->next->next; p2 = p2->next)
                if (p2->next->data > p2->next->next->data)
                {
                    temp = p2->next->next;
                    p2->next->next = temp->next;
                    temp->next = p2->next;
                    p2->next = temp;
                }
//    for (p1 = head->next, p2 = p1->next; p2->next->next; p2 = p2->next)
//        if (p1->data > p2->data && p1->data < p2->next->data)
//        {
//            p1->next = p2->next;
//            p2->next = p1;
//        }
}

//{
//    struct Node *temp,*q,*p;
//    for(q=head; q->next; q=q->next)
//        for(p=q->next; p->next; p=p->next)
//            if(p->next->data < q->next->data)
//                if(q->next==p)
//                {
//                    temp=p->next;
//                    p->next=p->next->next;
//                    temp->next=p;
//                    q->next=temp;
//                    p=temp;
//                }
//                else
//                {
//                    temp=p->next;
//                    p->next=q->next;
//                    q->next=temp;
//                    temp=p->next->next;
//                    p->next->next=q->next->next;
//                    q->next->next=temp;
//                }
//}
//{
//    struct Node *endpt;
//    struct Node *p;
//    struct Node *p1;
//    struct Node *p2;
//    p1=(struct Node *)malloc(sizeof(struct Node));
//    p1->next=head;
//    head=p1;
//    for (endpt=NULL; endpt!=head; endpt=p)
//    {
//        for (p=p1=head; p1->next->next!=endpt; p1=p1->next)
//        {
//            if (p1->next->data > p1->next->next->data)
//            {
//                p2 = p1->next->next;
//                p1->next->next = p2->next;
//                p2->next = p1->next;
//                p1->next = p2;
//                p = p1->next->next;
//            }
//        }
//    }
//    p1 = head;
//    head = head->next;
//    free(p1);
//    p1= NULL;
//    return head;
//}

