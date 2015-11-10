#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[20];//定义一个字符数组
    int a[20] = {0}, b[2] = {0};//定义并初始化两个整形数组
    char money[9][10] = {"元","十","百","千","万","十","百","千","亿"};
    char number[11][10] = {"零","壹","贰","叁","肆","伍","陆","柒","扒","玖","拾"};
    int i, j, x = 0, flage = 0;

    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
        if (str[i] == '.')
        {
            flage = 1;
            b[0] = str[i+1] - '0';//取得小数点后面的第一位数字
            b[1] = str[i+2] - '0';//取得小数点后面第二位的数字
            break;
        }
        else
        {
            a[i] = str[i] - '0';//正序取得小数点前面的所有数字
            x++;
        }
    for (i = 0; i < x; i++)
    {
        if (strcmp (number[a[i]],number[a[i+1]]) == 0)
            continue;
        else
        {
            printf("%s", number[a[i]]);
            printf("%s", money[x-i-1]);
        }
    }

    return 0;
}
