#include <stdio.h>
int main(void)
{
    int n, first, last, num;

    scanf("%d", &n);// ����
    for(first = 1; first <= n / 2; first++)// n1Ϊ�Ȳ����е�һ��
        for(last = first + 1; last < n; last++)// n2Ϊ�Ȳ��������һ��
            if((first + last) * (last - first + 1) == n * 2)// �õȲ����й�ʽ���
            {
                //�����Ⱦ�������
                for(num = first; num < last; num++)
                    printf("%d ", num);
                printf("%d\n", num);
            }

    return 0;
}
