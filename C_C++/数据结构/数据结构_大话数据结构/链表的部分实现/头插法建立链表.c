#include <stdio.h>
#include <stdlib.h>

typedef struct//�����ڵ���������
{
    int data;
    struct Node * Next;
} Node, *pNode;

pNode Creat_List( void );//����������һ������
void Traverse( pNode );  //��������������

int main( void )
{
    pNode Head;

    Head = Creat_List();
    Traverse( Head );

    return 0;
}

pNode Creat_List( void )
{
    pNode Head = ( pNode ) malloc ( sizeof ( Node ) );//�������һ��ͷ�ڵ���ڴ�ռ�

    Head->Next = NULL;//��ͷ�ڵ��ָ��ſ�

    while ( 1 )
    {
        pNode p = ( pNode ) malloc ( sizeof ( Node ) );//�������һ�������ڵ�

        scanf("%d", &p->data);//����������
        if ( 0 == p->data )//���б�׼���������ֵΪ0ʱ���ټ������ӽڵ�
            break;

        p->Next = Head->Next;//ÿһ�ζ����������Ľڵ�ָ���׽ڵ�
        Head->Next = p;//ͷ�ڵ�ָ���½ڵ�
    }

    return Head;
}
void Traverse( pNode Head )//��������
{
    while ( Head->Next )
    {
        Head = Head->Next;
        printf("%d ", Head->data);
    }
    return 0;
}
