#include<stdio.h>
typedef struct Node1
{
    int data;
    struct Node *nextNode;
}*NodeP,Node;//typedef���÷�����

void Creat(NodeP head,int data1)//��������
{
    NodeP p2 = head->nextNode;
    NodeP newNode;
    newNode = (NodeP)malloc(sizeof(Node));
    newNode->data = data1;
    newNode->nextNode = p2;
    head->nextNode = newNode;
}

void Delete(NodeP head, int key)//ɾ���ڵ�
{
    NodeP current = head->nextNode;//����һ��ͷ�ڵ�
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
        printf("Sorry,û���ҵ�Ҫɾ���Ľڵ�\n");
    }
}

void Insert(int place,int key,NodeP head)//����ڵ�
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
        printf("Sorry,��������\n");
    }
}

void Print(NodeP head)//��ӡ������
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
    int n,i;//�ڵ���
    int data;
    int key;
    int place;
    int key1;
    NodeP head;
    head = malloc(sizeof(Node));
    head->nextNode = NULL;
    //��������
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&data);
        Creat(head,data);
    }
    Print(head);

    //ɾ������
    scanf("%d",&key);
    Delete(head,key);
    Print(head);

    //�������
    scanf("%d%d",&place,&key1);
    Insert(place,key1,head);
    Print(head);
}
