#include <stdio.h>
int main(void)
{
    int n, k;//声明语句

    scanf("%d", &n);//输入要求的数字大小
    for (k = 2; k < n; )//循环判断
    {
        if (n % k != 0)//如果n%k不等于0则k不是n的质因数，k自加
            k++;
        else
        {
            n /= k;
            printf("%d ", k);//输出质因数
            k = 2;
        }
    }
    printf("%d", k);//输出最后一个质因数

    return 0;
}
