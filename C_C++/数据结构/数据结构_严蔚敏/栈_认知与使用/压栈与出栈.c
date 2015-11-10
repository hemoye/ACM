#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node * next;
} Node, * pNode;
typedef struct
{
    pNode top;
    pNode bottom;
} stack, * pstack;

void init(pstack);
void push(pstack, int);
void traverse(pstack);
void shanchu(pstack);
void clear(pstack);

int main(void)
{
    pNode s;

    init(&s);

    push(&s, 4);
    push(&s, 9);
    push(&s, 9);
    push(&s, 1);

    traverse(&s);
    putchar('\n');

   shanchu(&s);
   traverse(&s);
   putchar('\n');

    clear(&s);
    traverse(&s);

    return 0;
}
void init(pstack ps)
{
    ps->top = (pNode)malloc(sizeof(Node));
    ps->bottom = ps->top;
    ps->top->next = NULL;
}
void push(pstack ps, int val)
{
    pNode pNew = (pNode)malloc(sizeof(Node));
    pNew->data = val;
    pNew->next = ps->top;
    ps->top = pNew;
}
void traverse(pstack ps)
{
    pNode head = (pNode)malloc(sizeof(Node));
    head = ps->top;

    while(head != ps->bottom)
    {
        printf("%d", head->data);
        head = head->next;
    }
}
void shanchu(pstack ps)
{
//    pNode head = ps->top->next;
//    free(ps->top);
//    ps->top = head;
//两种删除方式都相同
      pNode head = ps->top;
      ps->top = head->next;
      free(head);
}
void clear(pstack ps)
{
    pNode p = ps->top;
    pNode q = NULL;

    while(p != ps->bottom)
    {
        q = p->next;
        free(p);
        p = q;
    }
    ps->top = ps->bottom;
}
