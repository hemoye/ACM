#include <stdio.h>

int main(void)
{
    int i, j, temp, jishu = 0, oushu = 0;//�������
    int a[100] = {0}, b[100] = {0}, c[100] = {0};//������������

    for (i = 0; i < 8; i++)
        scanf("%d", &a[i]);//��������
    for (i = 0; i < 8; i++)
        if (0 == a[i] % 2)//���a[i]��ż����ִ��if�ڲ����
        {
            b[oushu] = a[i];//��ż����������b
            oushu++;//����ż������
        }
        else
        {
            c[jishu] = a[i];//��������������c
            jishu++;//������������
        }
    for (i = 0; i < jishu; i++)
        for (j = 0; j < jishu - 1 - i; j++)
            if (c[j] < c[j+1])//�Ա������������������齵������
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
    for (i = 0; i < jishu; i++)
        for (j = 0; j < jishu - 1 - i; j++)
            if (b[j] > b[j+1])//�Ա���������ż����������������
            {
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
    for (i = 0; i < jishu; i++)//�����������������
        printf((0 == i) ? "%d" : " %d", c[i]);
    for (i = 0; i < oushu; i++)//���������ż������
        printf(" %d", b[i]);
    printf("\n");

    return 0;
}
