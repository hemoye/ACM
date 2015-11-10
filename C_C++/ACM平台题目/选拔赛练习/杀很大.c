#include <stdio.h>
#include <string.h>

int main(void)
{
    int t, T;
    scanf("%d", &T);//输入测试数据的组数
    for (t = 1; t <= T; t++)//控制循环次数
    {
        char ch, str[4];//定义声明
        int i, j, num, n, x, a[100];

        scanf("%d %d", &num, &n);//输入参赛的人数、杀的次数

        for (i = 0; i < n; i++)//控制出杀的次数
        {
            x = 0;
            scanf("%c %c %c", &str[0], &str[1], &str[2]);//输入三个字符

            if (num == 3)//如果只有三个人，那么就一定能杀到对方
            {
                printf("YES\n");//输出YES
                continue;//并跳过余下判断语句
            }
            else
            {

            }
        }
    }

    return 0;
}
