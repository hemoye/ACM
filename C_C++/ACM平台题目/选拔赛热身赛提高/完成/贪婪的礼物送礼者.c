#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[101];
    int data;
    int sum;
} Node;
int main(void)
{
    Node * p;
    int i, j, x, y, m, n, len;
    char str[101];

    scanf("%d", &len);
    p = (Node *)malloc(sizeof(Node) * len);
    for (i = 0; i < len; i++)
        p[i].data = p[i].sum = 0;//��ʼ���ṹ�����������
    for (i = 0; i < len; i++)
        scanf("%s", p[i].name);//�������е�����
    for (i = 0; i < len; i++)
    {
        scanf("%s%d%d", str, &m, &n);//���������ߵ����֡���Ǯ��Ŀ��Ҫ���͵���
        if (0 == n)
            continue;
        for (j = 0; j < len; j++)
            if (0 == strcmp(str, p[j].name))
            {
                p[j].sum += (m % n - m);//�����������µĽ�Ǯ��Ŀ
                break;
            }
        for (x = 0; x < n; x++)
        {
            scanf("%s", str);//���뱻�����ߵ�����
            if (0 == m)
                continue;
            for (y = 0; y < len; y++)
                if (0 == strcmp(str, p[y].name))
                    p[y].sum += m / n;//�����������õ��Ľ�Ǯ��Ŀ
        }
    }
    for (i = 0; i < len; i++)
        printf("%s %d\n", p[i].name, p[i].sum);

    return 0;
}
