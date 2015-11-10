//2013年1月14日 15:31:15
//目的：测试学习文件重定向的使用规则
//功能：从文件中读取数据，并将要输出的数据直接保存进入文件
#include <stdio.h>

int main( void )
{
    freopen("data.txt", "r", stdin);//从文件里面读出数据
    freopen("data.out", "w", stdout);//将输出数据存入到文件里面去

    int x, n = 0;

    while ( scanf("%d", &x) && x != 0 )
        n += x;//中间这一部分是对文件数据的操作

    printf("%d\n", n);//printf是将操作完成之后的数据保存进入文件

    return 0;
}
