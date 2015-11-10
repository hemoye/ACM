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
        p2 = p1->next;//p2�õ�p1����һ���ڵ�
        p1->next = NULL;//��ԭ����ĵ����ڶ�����Ч�ڵ�ſ�
        p2->next = p1;//ʹβ�ڵ�ָ����һ���ڵ�
        if (flage)
        {
            New_head->next = p2;//��ԭ�������һ���ڵ�ӵ��±�ͷ����
            flage = 0;
        }
        if (head == p1)//�����˵�һ���ڵ�֮��ſ�p1,��p2��ָ����ָ��սڵ�
        {
            free(p1);
            p2->next = NULL;
        }
    }
    return New_head;
}
