#include <stdio.h>
#include <string.h>//提供strlen函数

int main(void)
{
    int i, j, x, y, z, num[10];
    char c, ch[10], str[4906];

    gets(str);//获取字符串

    for (i = 0; i < 10; i++)
        num[i] = 1;//把数组中的每一个值都赋为1

    x = y = 0;
    for (i = 0; i < strlen(str); i++)//对字符串进行处理
    {
        z = 1;//初始化标识符z的值
        while (str[i] == str[i+1])
        {
            ch[x] = str[i];//把第一次出现的相同字符存入字符数组的第一个位置
            num[x]++;//表示相同字符的数量
            i++;
            z = 0;//改变标识符的值
        }
        if (z == 0)//判断标识符是否改变，如果改变则执行内部语句
        {
            x++;
            i--;
        }
    }
    for (i = 0; i < x - 1; i++)//冒泡法降序排序
        for (j = 0; j < x - 1 - i; j++)
            if (num[j] < num[j+1])
            {
                y = num[j];//把大的数值放在第一个位置
                num[j] = num[j+1];
                num[j+1] = y;

                c = ch[j];//与此同时字符的位置也跟着变动
                ch[j] = ch[j+1];
                ch[j+1] = c;
            }
    for (i = 0; i < num[0]; i++)//输出最长的等值子串
        printf("%c", ch[0]);
    printf("\n");

    return 0;
}
