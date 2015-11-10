#include<stdio.h>
typedef struct Node1
{
    int data;
    struct Node *nextNode;
}*NodeP,Node;//typedef的用法技巧

void Creat(NodeP head,int data1)//创建链表
{
    NodeP p2 = head->nextNode;
    NodeP newNode;
    newNode = (NodeP)malloc(sizeof(Node));
    newNode->data = data1;
    newNode->nextNode = p2;
    head->nextNode = newNode;
}

void Delete(NodeP head, int key)//删除节点
{
    NodeP current = head->nextNode;//定义一个头节点
    NodeP currentPri = head;
    while(current!=NULL&&current->data != key)
    {
        currentPri = current;
        current = current->nextNode;
    }
    if(current!=NULL)
    {
        currentPri->nextNode = current->nextNode;
        free(current);
    }
    else
    {
        printf("Sorry,没有找到要删除的节点\n");
    }
}

void Insert(int place,int key,NodeP head)//插入节点
{
    int i;
    NodeP current = head->nextNode;
    NodeP currentPri = head;
    for(i = 0;current != NULL&&i<place-1;i++)
    {
        currentPri = current;
        current = current->nextNode;
    }
    NodeP newNode ;
    newNode = malloc(sizeof(Node));
    newNode ->data = key;
    if(current)
    {
        newNode->nextNode = current;
        currentPri->nextNode = newNode;
    }
    else
    {
        printf("Sorry,输入有误\n");
    }
}

void Print(NodeP head)//打印单链表
{
    head = head->nextNode;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head ->nextNode;
    }
}

void main()
{
    int n,i;//节点数
    int data;
    int key;
    int place;
    int key1;
    NodeP head;
    head = malloc(sizeof(Node));
    head->nextNode = NULL;
    //创建链表
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&data);
        Creat(head,data);
    }
    Print(head);

    //删除操作
    scanf("%d",&key);
    Delete(head,key);
    Print(head);

    //插入操作
    scanf("%d%d",&place,&key1);
    Insert(place,key1,head);
    Print(head);
}
