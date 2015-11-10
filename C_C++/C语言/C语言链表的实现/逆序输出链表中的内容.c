#include <stdio.h>
#include <malloc.h>

struct stud
{
    int gread;
    struct stud * next;
};

struct stud * nixu(struct stud * Head)
{
    int flage = 1;
    struct stud * new_Head, * p1, * p2;

    new_Head = (struct stud *)malloc(sizeof(struct stud));
    while (NULL != Head->next->next)
    {
        for (p1 = Head; NULL != p1->next->next; p1 = p1->next);
        p2 = p1->next;
        p1->next = NULL;
        p2->next = p1;
        if (flage)
        {
            new_Head->next = p2;
            flage = 0;
        }
        if (p1 == Head)
        {
            free(p1);
            p2->next = NULL;
        }
    }

    return new_Head;
}

int main(void)
{
    int i, len;
    struct stud *  Head, * p1, * p2;

    Head = (struct stud *)malloc(sizeof (struct stud));
    Head->next = NULL;
    p1 = Head;

    scanf("%d", &len);
    for (i = 0; i < len; i++)
    {
        p2 = (struct stud *)malloc(sizeof (struct stud));
        scanf("%d", &p2->gread);
        p1->next = p2;
        p2->next = NULL;
        p1 = p2;
    }
    Head = nixu(Head);
    p1 = Head->next;
    while (p1)
    {
        printf("%d ", p1->gread);
        p1 = p1->next;
    }

    return 0;
}
