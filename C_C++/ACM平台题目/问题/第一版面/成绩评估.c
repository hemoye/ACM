#include <stdio.h>
int main(void)
{
    unsigned n;
    unsigned first, last, num;
    int flag = 0;

    scanf("%u", &n);//����
    for(first = 1; first <= n / 2; first++)// n1Ϊ�Ȳ����е�һ��
        for(last = first + 1; last < n; last++)// n2Ϊ�Ȳ��������һ��
            if((first + last) * (last - first + 1) == n * 2)// �õȲ����й�ʽ���
            {
                flag = 0;//�����Ⱦ�������
                for(num = first; num <= last; num++)
                {
                    flag++;
                    if (flag == 1)
                        printf("%d", num);
                    else
                        printf(" %d", num);
                }
                printf("\n");
            }
    if (0 == flag)
        printf("NONE\n");

    return 0;
}
