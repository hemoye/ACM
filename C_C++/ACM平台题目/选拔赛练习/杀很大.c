#include <stdio.h>
#include <string.h>

int main(void)
{
    int t, T;
    scanf("%d", &T);//����������ݵ�����
    for (t = 1; t <= T; t++)//����ѭ������
    {
        char ch, str[4];//��������
        int i, j, num, n, x, a[100];

        scanf("%d %d", &num, &n);//���������������ɱ�Ĵ���

        for (i = 0; i < n; i++)//���Ƴ�ɱ�Ĵ���
        {
            x = 0;
            scanf("%c %c %c", &str[0], &str[1], &str[2]);//���������ַ�

            if (num == 3)//���ֻ�������ˣ���ô��һ����ɱ���Է�
            {
                printf("YES\n");//���YES
                continue;//�����������ж����
            }
            else
            {

            }
        }
    }

    return 0;
}
