#include <stdio.h>

void hannuota(int n, char A, char B, char C)
{
//    �����һ������
//        ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
//    ����
//        �Ƚ�A�����ϵ�n-1�����ӽ���C�Ƶ�B
//        ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�B
//        ���B�����ϵ�n-1�����ӽ���A�Ƶ�C
    if (1 == n)
       printf("Move disk %d from %c to %c\n", n, A, C);
    else
    {
        hannuota(n-1, A, C, B);
        printf("Move disk %d from %c to %c\n", n, A, C);
        hannuota(n-1, B, A, C);
    }
}
int main(void)
{
    char ch1 = 'A', ch2 = 'B', ch3 = 'C';
    int n;

    scanf("%d", &n);
    hannuota(n, 'A', 'B', 'C');

    return 0;
}
