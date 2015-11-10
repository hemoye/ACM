#include <stdio.h>
int main(void)
{
    int n, first, last, num;

    scanf("%d", &n);// 输入
    for(first = 1; first <= n / 2; first++)// n1为等差数列第一项
        for(last = first + 1; last < n; last++)// n2为等差数列最后一项
            if((first + last) * (last - first + 1) == n * 2)// 用等差数列公式算和
            {
                //如果相等就输出结果
                for(num = first; num < last; num++)
                    printf("%d ", num);
                printf("%d\n", num);
            }

    return 0;
}
