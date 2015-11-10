#include <stdio.h>

void hannuota(int n, char A, char B, char C)
{
//    如果是一个盘子
//        直接将A柱子上的盘子从A移到C
//    否则
//        先将A柱子上的n-1个盘子借助C移到B
//        直接将A柱子上的盘子从A移到B
//        最后将B柱子上的n-1个盘子借助A移到C
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
