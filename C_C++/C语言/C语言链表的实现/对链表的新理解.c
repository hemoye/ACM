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
    head = (Nodep)malloc(sizeof(Node));//����һ��ͷ�ڵ�
    p1 = head;
    while(len--)
    {
        p2 = (Nodep)malloc(sizeof(Node));
        scanf("%d", &p2->data);
        p1->next = p2;//��p2�ӵ����һ���ڵ����
        p2->next = NULL;//�ſ�p2��ָ��
        p1 = p2;//�����ļ��庬�壺��p1ÿһ�ζ�����Ϊ���һ���ڵ�
    }

    return head;
}
