#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int front;//队首
    int rear;//队尾
    int * pBase;//作为下标的指引
} Queue;

void init(Queue *);//初始化队列
void en_Queue(Queue *, int );//入队
int judge(Queue * pQ);//判断队列是否为空
void traverse_Queue(Queue *);//遍历队列
void out_Queue(Queue *, int *);//出队

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
        printf("您此次出队的元素是:%d\n", val);
    else
        printf("出队失败！\n");
    traverse_Queue(&Q);

    return 0;
}
void init(Queue * pQ)//初始化队列
{
    pQ->pBase = (int *)malloc(sizeof(int) * 6);
    pQ->front = pQ->rear = 4;//初始化，可以从任意一个小于长度减1的非负数开始(也就是说，如果最大长度是6，那么最大的下标最大只能是4)
}
void en_Queue(Queue * pQ, int val)
{
    if ((pQ->rear+1) % 6 == pQ->front)
        printf("队列已满,不能继续存储！\n");
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
