#include <stdio.h>

int main(void)
{
    int n, k, i, j;//�������

    scanf("%d", &n);//�����������
    int a[n];//����һ������Ϊn������

    for (i = 0; i < n; i++)//�������С�������1~n
        a[i] = i + 1;
    for (i = n, j = 0; i > 0; i--)
    {
        for (k = 0; k < 3; k++)
            if (++j > i - 1)
                j = 0;

        if (j)
            for (k = --j; k < i - 1; k++)
                a[k] = a[k+1];
    }
    printf("%d\n", a[0]);

    return 0;
}
