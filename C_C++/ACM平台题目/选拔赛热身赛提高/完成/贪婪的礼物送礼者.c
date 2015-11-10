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
        p[i].data = p[i].sum = 0;//初始化结构体里面的内容
    for (i = 0; i < len; i++)
        scanf("%s", p[i].name);//输入所有的人名
    for (i = 0; i < len; i++)
    {
        scanf("%s%d%d", str, &m, &n);//输入赠送者的名字、金钱数目，要赠送的人
        if (0 == n)
            continue;
        for (j = 0; j < len; j++)
            if (0 == strcmp(str, p[j].name))
            {
                p[j].sum += (m % n - m);//赠送者所余下的金钱数目
                break;
            }
        for (x = 0; x < n; x++)
        {
            scanf("%s", str);//输入被赠送者的名字
            if (0 == m)
                continue;
            for (y = 0; y < len; y++)
                if (0 == strcmp(str, p[y].name))
                    p[y].sum += m / n;//被赠送者所得到的金钱数目
        }
    }
    for (i = 0; i < len; i++)
        printf("%s %d\n", p[i].name, p[i].sum);

    return 0;
}
