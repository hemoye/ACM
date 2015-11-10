#include <stdio.h>
int main(void)
{
    unsigned n;
    unsigned first, last, num;
    int flag = 0;

    scanf("%u", &n);//输入
    for(first = 1; first <= n / 2; first++)// n1为等差数列第一项
        for(last = first + 1; last < n; last++)// n2为等差数列最后一项
            if((first + last) * (last - first + 1) == n * 2)// 用等差数列公式算和
            {
                flag = 0;//如果相等就输出结果
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
