#include<stdio.h>
struct Node
{
   int data;
   struct Node*next;
};

void Insert(struct Node *head,int data)
{
    struct Node *current = head->next;
    struct Node *currentPri = head;
    struct Node *nNode;
    nNode = malloc(sizeof(struct Node));
    nNode->data = data;
    while(current&&current->data < data)
    {
        currentPri = current;
        current = current->next;
    }
    nNode->next = current;
    currentPri->next = nNode;
}

void Pirnt(struct Node *head)
{
    head = head->next;
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
void main()
{
    int m;
    int i,data;
    char str[100];
    struct Node *head;
    head = malloc(sizeof(struct Node));
    head->next = NULL;
    gets(str);
    getchar();//接受空行
    getchar();//接受m
    getchar();//接受=
    scanf("%d",&m);
    for(i = 0;i<m;i++)
    {
        scanf("%d",&data);
        Insert(head,data);
    }
    Pirnt(head);
}

