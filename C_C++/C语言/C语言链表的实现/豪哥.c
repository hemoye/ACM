#include<stdio.h>
#include<malloc.h>

struct Num
{
    int a;
    struct Num *next;
};

struct Num *  reversed(struct Num * head)
{
    int ok = 1;
    struct Num * p1, *p2;
    struct Num *new_head = (struct Num *)malloc(sizeof(struct Num));
    while( NULL != head->next->next )
    {
        for( p1 = head; NULL != p1->next->next; p1 = p1->next )
            ;
        p2 = p1->next;
        p1->next = NULL;
        p2->next = p1;
        if( ok )
        {
            new_head->next = p2;
            ok = 0;
        }
        if( p1 == head )
        {
            free(p1);
            p2->next = NULL;
        }
    }
    return new_head;
}

int main(void)
{
    int i,len;
    struct Num *p1,*p2,*p,*q;
    struct Num *head;
    head = (struct Num *)malloc(sizeof(struct Num));
    head->next = NULL;
    head->a = 0;

    p1 = head;
    for (i = 0; i < 5; i++)
    {
        p2 = (struct Num *)malloc(sizeof(struct Num));
        p2->a = i+1;
        p1->next = p2;
        p2->next = NULL;
        p1 = p2;
    }

    head = reversed(head);
    p1 = head->next;
    while (p1)
    {
        printf("%d\n",p1->a);
        p1 = p1->next;
    }
    return 0;
}
