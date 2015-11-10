#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    char str[1001];//定义声明
    int n, z;

    scanf("%d\n", &n);//输入测试数据的组数

    for (z = 1; z <= n; z++)
    {
        int i, sum, zonghe, oushu = 0, jishu = 0;//定义并初始化数据
        gets(str);
        for (i = 0; i < strlen(str); i++)
        {
            if (i % 2 == 0)
                oushu += (str[i] - '0');//求的偶数位上的和
            else
                jishu += (str[i] - '0');//求的奇数位上的和
        }
        //printf("%d %d\n", oushu, jishu);

        zonghe = oushu + jishu;//求的各个位数上的和
        sum = fabs(oushu - jishu);//求的奇位数与偶位数之差的绝对值

        printf("Case %d:\n", z);//格式控制
        if (zonghe % 3 == 0)//判断是否能被3整除
            printf("yes ");
        else
            printf("no ");

        if (sum % 11 == 0)//如果奇偶位差的绝对值能被11整除则表明原数字能被11整除
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
