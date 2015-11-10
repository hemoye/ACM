#include <stdio.h>
#include <string.h>//为字符函数提供原型

int main(void)
{
    int dachengfa(char * , char * , int );

    unsigned m, n;//声明语句，定义两个无符号整形变量

    scanf ("%u", &m);//输入测试数据的组数
    for (n = 0; n < m; n++)//控制测试数据的组数
    {
        char str1[1000], str2[1000];//定义两个一维字符数组
        int a[100] = {0}, b[100] = {0}, c[1000] = {0};//定义并初始化三个一维数组
        int i, j, x, y, len, z = 0;//声明语句

        scanf("%s%s", str1, str2);//获得两个字符串
        if (strcmp (str1, str2) == 0)//如果被除数等于除数
        {
            printf("1\n");//则输出1，并跳过余下判断
            continue;
        }
        else if (strcmp (str1, str2) < 0)//如果被除数大于除数
        {
            printf("0\n");//则输出0，并跳过余下判断
            continue;
        }
        else
        {
            len = strlen(str1) - strlen(str2);
            for (i = 0; i < strlen(str1); i++)//把除数的所有字符转化成数字并存入数组
                a[i] = str1[i] - '0';
            for (i = 0; i < strlen(str2); i++)//把被除数的所有字符转化成数字并存入数组
                b[i] = str2[i] - '0';
            for (i = 0; i < len; i++)
            {
                if ()
            }
    }

    return 0;
}
int dachengfa(char * a, char * b; int len, int z)
{
    int i = z;
    int j, t;

    for (t = 1; t <= 9; t++)
    {

    }
}
