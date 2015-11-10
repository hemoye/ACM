#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node//定义结构体
{
    int data;
    struct Node *pNext;
};

int main(void)
{
    int i, len;
    struct Node *p1, *p2;
    struct Node *Head;//定义一个struct NOde类型的指针
    Head = (struct Node *)malloc(sizeof(struct Node));//动态分配内存
    Head->pNext = NULL;//初始化结构体里面的结构体变量
    //Head->data = 0;//初始化结构体里面的整形数据
    p1 = Head;
    for(i = 0; i < 5; i++)
    {
        p2 = (struct Node *)malloc(sizeof(struct Node));//动态分配内存
        if(p2==NULL)//确认是否分配内存成功
        {
            printf("分配内存失败!\n");
            exit(-1);//如果分配失败则终止程序
        }
        scanf("%d", &p2->data);//获得第一个整形数据
        p1->pNext = p2;
        p2->pNext = NULL;
        p1 = p2;  //循环构建，p1储存了p2的地址就继续向下构建，直到循环终止
    }
    p1 = Head->pNext;
    while(p1)
    {
        printf("%d ", p1->data);
        p1 = p1->pNext;
    }
    return 0;
}
