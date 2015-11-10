#include <stdio.h>
#include <stdlib.h>

struct Node//构造结构体类型
{
    int data;//数据域
    struct Node * next;//指针域
};
void Sort(struct Node * head)//排序函数
{
    struct Node * p2, * temp;//定义声明
    struct Node * p1 = (struct Node *)malloc(sizeof(struct Node));

    for (p1->next = head; p1; p1 = p1->next)//冒泡法交换链表的指针域
        for (p2 = head; p2->next->next; p2 = p2->next)
            if (p2->next->data > p2->next->next->data)//以数值大小为依据，升序排序
            {//目的：交换p2的下一个节点与p2的下下一个的指针域 89
                temp = p2->next->next;//保存p2的下一个节点的指向
                p2->next->next = temp->next;//在原链表中删除p2的下一个的下一个节点(也就是指向p2下面的第三个节点)
                temp->next = p2->next;//temp指向p2的下一个节点
                p2->next = temp;//让p2指向temp
            }
    return ;
}
int main(void)
{
    int len = 5;//控制节点个数
    struct Node * head, * p1, * p2;//定义三个结构体类型变量
    head = (struct Node *)malloc(sizeof(struct Node));//动态分配内存
    head->next = NULL;//使头节点指向空
    p1 = head;//把p1作为首节点

    while (len--)//获取五个节点的数据域
    {
        p2 = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &p2->data);//获取p2节点的指针域
        p1->next = p2;//使链表的尾节点指向p2(即把每一个输入数据都接到表尾)
        p2->next = NULL;//使p2的指针域为空
        p1 = p2;//把p2赋给p1，是p1总是作为一个尾节点(这样总是可以接上下一个节点)
    }
    Sort(head);//函数调用
    while(head->next)//遍历
    {
        head = head->next;
        printf("%d ", head->data);//输出
    }
    return 0;
}
