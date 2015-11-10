/*2012年11月29日 12:25:15
  功能：字符与数字之间的相互转换
  目的：了解数字与字符之间相互转换的关系
*/
#include <stdio.h>

int main(void)
{
    int a = 4, c = 9;
    char b = '3', d = '8';

    a = b - '0';
    d = c + '0';

    printf("数字%d转化成字符是：%c\n", a, b);
    printf("字符%c转换成数字是：%d\n", d, c);

    return 0;
}
/*在clodblacks输出的结果是：
**************************
数字3转化成字符是：3
字符9转换成数字是：9
**************************
*/
