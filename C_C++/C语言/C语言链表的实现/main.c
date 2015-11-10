#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int date;
    struct Node *pre;
    struct Node *next;
}Node;
void Creat_Double_List(Node * head,int n)//创建双向循环链表
{
    Node *p = head;
    while(n --)
    {
        Node *pnew = (Node *)malloc(sizeof(Node));
        scanf("%d",&pnew->date);
        pnew->pre = p;
        p->next = pnew;

        pnew->next = head;
        head->pre = pnew;
        p=pnew;
    }
}
void Display_List(Node *head,int n)//遍历双向链表
{
    int i = 0;
    Node *p = head;
    while(i < n)
    {
        p=p->next;
        printf("%d ",p->date);
        i++;
    }
    printf("\n");
}
void Inser_List(Node *head,int size,int lenth,int n)///双向链表数据插入
{
    int i=0;
    Node *p = head;
    Node *pnew = (Node *)malloc(sizeof(Node));

    Node *pn = (Node *)malloc(sizeof(Node));
    pn->date = n;

    if(size == 1)
    {
        pnew = head->next;
        pnew->pre = pn;
        pn->next = head->next;

        head->next = pn;
        pn->pre = head;
    }
    else
    {
        while(i<=lenth+1)
        {
            p=p->next;
            i++;
            if(i == size-1)
            {
                pnew=p->next;
                pn->next = pnew;
                pnew->pre = pn;

                p->next = pn;
                pn->pre = p;
            }
        }
    }
}
void Del_List(Node *head,int size,int lenth) ///双向链表删除节点
{
    int i = 0;
    Node *p = head;
    Node *pnew = (Node *)malloc(sizeof(Node));
    Node *pnew1 = pnew;
    if(size == 1)
    {
        pnew = head->next;
        head->next = pnew->next;
        pnew1 = pnew->next;
        pnew1->pre = head;

        free(pnew);
    }
    else
        while(i<=lenth)
        {
            p=p->next;
            i++;
            if(i == size-1)
            {
                pnew = p->next;
                p->next = pnew->next;
                pnew1=pnew->next;
                pnew1->pre = p;
                free(pnew);
            }
        }
}
int main()
{
    int n;
    scanf("%d",&n);
    Node *head = (Node *)malloc(sizeof(Node));
    Creat_Double_List(head,n);
    Display_List(head,n);

    int size,num;//插入
    scanf("%d %d",&size,&num);
    Inser_List(head,size,n,num);
    Display_List(head,n+1);

    int del_size;//删除
    scanf("%d",&del_size);
    Del_List(head,del_size,n);
    Display_List(head,n);
    return 0;
}
