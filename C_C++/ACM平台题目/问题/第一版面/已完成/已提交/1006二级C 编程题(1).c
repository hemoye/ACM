#include <stdio.h>
int main(void)
{
    int gread;//声明语句
    int num1 = 0, num2 = 0, num3 = 0;//声明并赋值语句

    while (scanf("%d", &gread) != EOF)
    {
        if (gread <= 0)
            break;
        if (gread >= 85)//统计优秀的人数
            num1++;
        if (gread >= 60 && gread < 85)//统计通过的人数
            num2++;
        else if (gread < 60 && gread > 0)//统计不及格的人数
            num3++;
    }

    printf(">=85:%d\n60-84:%d\n<60:%d\n", num1, num2, num3);
    //输出统计数据
    return 0;
}
