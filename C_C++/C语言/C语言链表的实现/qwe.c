#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node//����ṹ��
{
    int data;
    struct Node *pNext;
};

int main(void)
{
    int i, len;
    struct Node *p1, *p2;
    struct Node *Head;//����һ��struct NOde���͵�ָ��
    Head = (struct Node *)malloc(sizeof(struct Node));//��̬�����ڴ�
    Head->pNext = NULL;//��ʼ���ṹ������Ľṹ�����
    //Head->data = 0;//��ʼ���ṹ���������������
    p1 = Head;
    for(i = 0; i < 5; i++)
    {
        p2 = (struct Node *)malloc(sizeof(struct Node));//��̬�����ڴ�
        if(p2==NULL)//ȷ���Ƿ�����ڴ�ɹ�
        {
            printf("�����ڴ�ʧ��!\n");
            exit(-1);//�������ʧ������ֹ����
        }
        scanf("%d", &p2->data);//��õ�һ����������
        p1->pNext = p2;
        p2->pNext = NULL;
        p1 = p2;  //ѭ��������p1������p2�ĵ�ַ�ͼ������¹�����ֱ��ѭ����ֹ
    }
    p1 = Head->pNext;
    while(p1)
    {
        printf("%d ", p1->data);
        p1 = p1->pNext;
    }
    return 0;
}
