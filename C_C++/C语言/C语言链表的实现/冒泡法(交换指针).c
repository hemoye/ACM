#include <stdio.h>
#include <stdlib.h>

struct Node//����ṹ������
{
    int data;//������
    struct Node * next;//ָ����
};
void Sort(struct Node * head)//������
{
    struct Node * p2, * temp;//��������
    struct Node * p1 = (struct Node *)malloc(sizeof(struct Node));

    for (p1->next = head; p1; p1 = p1->next)//ð�ݷ����������ָ����
        for (p2 = head; p2->next->next; p2 = p2->next)
            if (p2->next->data > p2->next->next->data)//����ֵ��СΪ���ݣ���������
            {//Ŀ�ģ�����p2����һ���ڵ���p2������һ����ָ���� 89
                temp = p2->next->next;//����p2����һ���ڵ��ָ��
                p2->next->next = temp->next;//��ԭ������ɾ��p2����һ������һ���ڵ�(Ҳ����ָ��p2����ĵ������ڵ�)
                temp->next = p2->next;//tempָ��p2����һ���ڵ�
                p2->next = temp;//��p2ָ��temp
            }
    return ;
}
int main(void)
{
    int len = 5;//���ƽڵ����
    struct Node * head, * p1, * p2;//���������ṹ�����ͱ���
    head = (struct Node *)malloc(sizeof(struct Node));//��̬�����ڴ�
    head->next = NULL;//ʹͷ�ڵ�ָ���
    p1 = head;//��p1��Ϊ�׽ڵ�

    while (len--)//��ȡ����ڵ��������
    {
        p2 = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &p2->data);//��ȡp2�ڵ��ָ����
        p1->next = p2;//ʹ�����β�ڵ�ָ��p2(����ÿһ���������ݶ��ӵ���β)
        p2->next = NULL;//ʹp2��ָ����Ϊ��
        p1 = p2;//��p2����p1����p1������Ϊһ��β�ڵ�(�������ǿ��Խ�����һ���ڵ�)
    }
    Sort(head);//��������
    while(head->next)//����
    {
        head = head->next;
        printf("%d ", head->data);//���
    }
    return 0;
}
