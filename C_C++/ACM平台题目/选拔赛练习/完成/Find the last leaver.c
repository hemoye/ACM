#include <stdio.h>
#include <string.h>

int main(void)
{
    void jiaohuan(char * str,  char * ch);//定义函数

    int n, i, j, t = 0;//定义声明

    while(scanf("%d", &n) != EOF)//输入人数
    {
        char str[2*n][1001];//定义声明
        int temp, time[2*n][2], shijian[2*n];

        for (i = 0; i < 2 * n; i++)
        {
            scanf("%s %d:%d", str[i], &time[i][0], &time[i][1]);//循环控制输入学生的进入时间和离开时间
            shijian[i] = time[i][0] * 60 + time[i][1];//用分钟表示同学进入或离开教室的时间
        }

        printf("Case #%d:\n", ++t);//输出格式控制

        for (i = 0; i < 2 * n - 1; i++)//对时间进行排序
            for (j = 0; j < 2 * n - i - 1; j++)
                if (shijian[j] > shijian[j+1])
                {
                    temp = shijian[j];
                    shijian[j] = shijian[j+1];
                    shijian[j+1] = temp;

                    jiaohuan(str[j], str[j+1]);//字符串的位置跟随时间的变动而变动
                }

        printf("%s\n%s\n%d\n", str[0], str[2*n-1], shijian[2*n-1] - shijian[0]);//输出结果
    }

    return 0;
}
void jiaohuan(char * str,  char * ch)//定义函数
//函数功能：互换两个字符串
{
    char * c[1001];

    strcpy(c, str);
    strcpy(str, ch);
    strcpy(ch, c);
}
