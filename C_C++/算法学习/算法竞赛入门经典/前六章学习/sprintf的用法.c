#include <stdio.h>
#define  MAX 20

int main( void )
{
    int x, a;
    char str[MAX];

    scanf("%d", &x);

    sprintf(str, "%d", x);//把一个数字转化成字符串

    puts(str);

    sscanf(str, "%d", &a);//把一个字符串转化成数字
    printf("->%d\n", a);

    return 0;
}
