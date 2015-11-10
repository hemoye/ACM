#include <stdio.h>
int Judge(int year)
{
    if (year%400==0 || (year%4==0&&year%100!=0))
        return 1;
    else
        return 0;
}
int main(void)
{
    int i, j, z, n, x, sum = 0, num = 0, count[7] = {0};//一次存储星期一到星期日
    int day[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    scanf("%d", &n);
    for (i = 1900; i < 1900 + n; i++)
    {
        j = Judge(i);//判断是否是闰年
        for (z = 0; z < 12; z++)
        {
            num = sum + 13;//
            count[num%7]++;//计算每一个月的13号是星期几
            sum += day[j][z];//累加每一个月的天数
        }
    }
    printf("%d %d", count[6], count[0]);//输出星期六、星期天
    for (i = 1; i <= 5; i++)
        printf(" %d", count[i]);//依次输出星期一到星期五
    printf("\n");
    return 0;
}
