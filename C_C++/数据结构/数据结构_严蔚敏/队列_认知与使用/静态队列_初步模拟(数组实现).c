#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int front;//����
    int rear;//��β
    int * pBase;//��Ϊ�±��ָ��
} Queue;

void init(Queue *);//��ʼ������
void en_Queue(Queue *, int );//���
int judge(Queue * pQ);//�ж϶����Ƿ�Ϊ��
void traverse_Queue(Queue *);//��������
void out_Queue(Queue *, int *);//����

int main(void)
{
    Queue Q;
    int val;

    init(&Q);

    en_Queue(&Q, 1);
    en_Queue(&Q, 2);
    en_Queue(&Q, 3);
    en_Queue(&Q, 4);
    en_Queue(&Q, 5);
    en_Queue(&Q, 6);
    en_Queue(&Q, 7);
    en_Queue(&Q, 8);

    traverse_Queue(&Q);

    out_Queue(&Q, &val);
    if (judge(&Q))
        printf("���˴γ��ӵ�Ԫ����:%d\n", val);
    else
        printf("����ʧ�ܣ�\n");
    traverse_Queue(&Q);

    return 0;
}
void init(Queue * pQ)//��ʼ������
{
    pQ->pBase = (int *)malloc(sizeof(int) * 6);
    pQ->front = pQ->rear = 4;//��ʼ�������Դ�����һ��С�ڳ��ȼ�1�ķǸ�����ʼ(Ҳ����˵�������󳤶���6����ô�����±����ֻ����4)
}
void en_Queue(Queue * pQ, int val)
{
    if ((pQ->rear+1) % 6 == pQ->front)
        printf("��������,���ܼ����洢��\n");
    else
    {
        pQ->pBase[pQ->rear++] = val;
        pQ->rear %= 6;
    }
}
void traverse_Queue(Queue * pQ)
{
    int index = pQ->front;

    while(index != pQ->rear)
    {
        printf("%d ", pQ->pBase[index]);
        index = (index+1) % 6;
    }
    printf("\n");
}
int judge(Queue * pQ)
{
    if (pQ->front == pQ->rear)
        return 0;
    return 1;
}
void out_Queue(Queue * pQ, int * pVal)
{
    if (pQ->rear == pQ->front)
        return;
    *pVal = pQ->pBase[pQ->front++];
}
