#include <stdio.h>
#include <stdlib.h>

typedef struct//构建节点数据类型
{
    int data;
    struct Node * Next;
} Node, *pNode;

pNode Creat_List( void );//函数：创建一个链表
void Traverse( pNode );  //函数：遍历链表

int main( void )
{
    pNode Head;

    Head = Creat_List();
    Traverse( Head );

    return 0;
}

pNode Creat_List( void )
{
    pNode Head = ( pNode ) malloc ( sizeof ( Node ) );//申请分配一个头节点的内存空间

    Head->Next = NULL;//将头节点的指向放空

    while ( 1 )
    {
        pNode p = ( pNode ) malloc ( sizeof ( Node ) );//申请分配一个工作节点

        scanf("%d", &p->data);//输入数据域
        if ( 0 == p->data )//评判标准：当输入的值为0时不再继续增加节点
            break;

        p->Next = Head->Next;//每一次都让让新增的节点指向首节点
        Head->Next = p;//头节点指向新节点
    }

    return Head;
}
void Traverse( pNode Head )//遍历链表
{
    while ( Head->Next )
    {
        Head = Head->Next;
        printf("%d ", Head->data);
    }
    return 0;
}
