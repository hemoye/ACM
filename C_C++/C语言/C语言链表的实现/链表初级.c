#include <stdio.h>
#include <stdlib.h>

struct Node//定义一个结构体类型
{
    int number;
    struct Node * next;
};

struct Node * nixu(struct Node * );//函数声明

int main(void)
{
    int i;
    struct Node * Head, * p1, * p2;//定义声明
    Head = (struct Node *)malloc(sizeof(struct Node));//动态分配内存
    Head->next = NULL;
    p1 = Head;
    for (i = 0; i < 5; i++)
    {
        p2 = (struct Node *)malloc(sizeof(struct Node));//动态分配内存
        scanf("%d", &p2->number);
        p1->next = p2;//p1指向p2
        p2->next = NULL;//p2指向空地址
        p1 = p2;//把p2赋给p1
    }
    Head = nixu(Head);
    p1 = Head->next;
    while(p1)//输出
    {
        printf("%d\n", p1->number);
        p1 = p1->next;
    }

    return 0;
}
struct Node * nixu(struct Node * Head)
{
    struct Node * new_head, *p1, *p2;//定义声明
    int flage = 1;//标识符，用来判断是否开辟头节点

    new_head = (struct Node *)malloc(sizeof(struct Node));
    while (NULL != Head->next->next)
    {
        for (p1 = Head; NULL != p1->next->next; p1 = p1->next);
        p2 = p1->next;
        p1->next = NULL;
        p2->next = p1;
        if (flage)
        {
            new_head->next = p2;
            flage = 0;
        }
        if (p1 == Head)
        {
            free(p1);
            p2->next = NULL;
        }
    }

    return new_head;
}
