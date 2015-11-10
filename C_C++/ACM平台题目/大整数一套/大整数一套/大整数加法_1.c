#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, k, max, s, sum;//声明语句
    int a[1000] = {0}, b[1000] = {0};//定义数组
    char s1[1000], s2[1000];//定义字符串数组

    scanf ("%s%s", s1, s2);//输入字符串

    k = max = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);//取得最大的字符串长度

    for(i = k,j = strlen(s1) - 1; j >= 0; i--, j--)//把字符转化并存储进入数组
        a[i] = s1[j] - '0';
    for(i = k, j = strlen(s2) - 1; j >= 0; i--, j--)//把字符转化并存储进入数组
        b[i] = s2[j] - '0';
    for(i = k; i > 0; i--)//循环累加各个位置上面的数字
    {
        a[i] += b[i];
        if(a[i] > 9)//十进制（如果数字大于10，则进一）
        {
            a[i] -= 10;
            a[i-1]++;
        }
    }

    if(a[0])//如果第一位不是0，则输出
        for(i = 0; i <= k; i++)
            printf("%d",a[i]);
    else//否则从第二个数字开始输出
        for(i=1; i<=k; i++)
            printf("%d",a[i]);

    return 0;
}
