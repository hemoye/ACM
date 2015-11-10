/*#include <stdio.h>
#include <string.h>

int main(void)
{
    int sum, t;

    scanf("%d", &sum);//输入测试数据的组数
    for (t = 1; t <= sum; t++)
    {
        int n, i, j, zt[3], yanse[3], daxiao[3];//定义声明
        int flage = 1;//标识符

        scanf("%d", &n);//输入司马懿状态的数目
        for (i = 0; i < n; i++)
            scanf("%d", &zt[i]);//输入司马懿的状态

        for (i = 0; i < 3; i++)//输入诸葛亮能够看到的牌的大小以及颜色
            scanf("%d %d", &daxiao[i], &yanse[i]);

        printf("Case %d: ", t);//格式控制

        if (zt[0] != 3)//如果司马懿的第一个状态不是闪电
        {
            printf("天助司马懿不助诸葛亮! ");//则输出如左语句并跳过下面的语句
            continue;
        }
        else//如果司马懿的第一个状态是闪电则继续判定
        {
            for (i = 0; i < 3; i++)
                if (yanse[i] == 4 && (daxiao[i] >= 2 && daxiao[i] <= 9))//如果诸葛亮看到的3张牌中有一张是黑桃2~9
                {
                    flage = 0;//令标志为0
                    printf("天助诸葛亮不助司马懿! ");//则输出如左语句
                }
            if (flage)//如果标志不为0，则输出如下语句
                printf("天助司马懿不助诸葛亮! ");
        }
        for (i = 0; i < n; i++)
            if (zt[i] == 3)
               printf("%d\n", i + 1);
    }

    return 0;
}
*/
#include <stdio.h>

int main(void)
{
    int sum, n, i, t, m;
    int a[3], b[6];
    scanf("%d", &sum);
    for (m = 1; m <= sum; m++)
    {
        int flage=0;
        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        if(n==1)
            flage=1;
        else if(n==2||n==3)
        {
            if(a[0]==3)
                flage=1;
        }
        for(i=0; i<6; i++)
            scanf("%d", &b[i]);
        if(flage==1)
        {
            for(i=0; i<6; i++)
                if((i+1)%2==0&&b[i]==4&&(b[i-1]>=2&&b[i-1]<=9))
                {
                    printf("Case %d: 天助诸葛亮不助司马懿! ", m);
                    flage = 0;
                }
            if (flage)
                printf("Case %d: 天助司马懿不助诸葛亮! ", m);
        }
        else
            printf("Case %d: 天助司马懿不助诸葛亮! ", m);
        for(i=0; i<n; i++)
            if(a[i]==3)
                printf("%d\n", i+1);
    }
    return 0;
}
