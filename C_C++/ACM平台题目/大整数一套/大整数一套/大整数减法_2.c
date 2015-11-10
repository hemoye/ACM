/*2012年11月30日 16:05:29
  功能：求两个大整数的差
  目的：模拟计算机的四则运算
*/
#include <stdio.h>
#include <string.h>//为字符函数提供原型

int main(void)
{
    int judge(char str1[], char str2[]);//函数声明

    int i, j, flage;//声明语句
    int a[1000] = {0}, b[1000] = {0};//定义并初始化两个数组
    char str1[1000], str2[1000];//定义两个字符串

    scanf("%s%s", str1, str2);

    if (strcmp (str1, str2) == 0)
    {
        printf("0\n");
        return 0;
    }

    flage = judge(str1, str2);//调用函数，并用flage接收函数的返回值

    if (flage == 1)//如果减数大于被减数，则执行
    {
        for (i = strlen(str1) - 1, j = strlen(str1) - 1; j >= 0; i--, j--)
            a[i] = str1[i] - '0';//把数字字符转换成数字并保存在数组
        for (i = strlen(str1) - 1, j = strlen(str2) - 1; j >= 0; i--, j--)
            b[i] = str2[j] - '0';
        for (i = strlen(str1); i >= 0; i--)
        {//循环想减
            if (b[i] > a[i])//如果被减数在某一位置上大于减数则减数的上一位自减1
            {
                a[i-1] -= 1;
                a[i] = a[i] + 10 - b[i];
            }
            else
                a[i] -= b[i];
        }
        if (a[0])//如果第一位数字不是零就输出
            for (i = 0; i < strlen(str1); i++)
                printf("%d", a[i]);
        else//否则不输出
            for (i = 1; i < strlen(str1); i++)
                printf("%d", a[i]);
    }
    else//如果被减数大于减数，则执行else内部语句
    {
        for (i = strlen(str2) - 1, j = strlen(str2) - 1; j >= 0; i--, j--)
            a[i] = str2[i] - '0';
        for (i = strlen(str2) - 1, j = strlen(str1) - 1; j >= 0; i--, j--)
            b[i] = str1[j] - '0';
        for (i = strlen(str2); i >= 0; i--)
        {
            if (b[i] > a[i])
            {
                a[i-1] -= 1;
                a[i] = a[i] + 10 - b[i];
            }
            else
                a[i] -= b[i];
        }
        printf("-");
        if (a[0])
            for (i = 0; i < strlen(str2); i++)
                printf("%d", a[i]);
        else
            for (i = 1; i < strlen(str2); i++)
                printf("%d", a[i]);
    }

    return 0;
}
int judge(char str1[], char str2[])//判断字符串数字大小并返回真假
{
    int i;

    if (strlen(str1) < strlen(str2))//如果第二个字符串大则返回0
        return 0;
    else if (strlen(str1) > strlen(str2))//如果第一个字符串大则返回1
        return 1;
    else//当两个字符串长度一样的时候，正序循环比较每一个字符的大小
        if (strcmp (str1, str2) > 0)
            return 1;
        else if (str1[i] < str2[i])
            return 0;
}
/*结论：在初步使用字符串函数的时候不了解strcmp函数的规则
  strcmp函数的使用规则：
  1、不是比较字符串的长度，额数比较字符串的大小
  2、前者大则返回1，后者大则返回-1，两者完全相等则返回0
  3、比较的规则是：
     a. 从首位置开始比较
     b. 系统自动把字符转化成ASCⅡ的大小
     c. 按照字符所对应的ASCⅡ大小进行逐个比较，
        若比较的字符相同，则用下一位进行比较，直到
        有一组字符不相同，此时返回比较值。
*/
