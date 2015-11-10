#include <stdio.h>

int main(void)
{
    int a;
    long b;
    long long c;

    while (scanf("%d %ld %lld", &a, &b, &c) != EOF)
        printf("%d %ld %lld\n", a, b, c);

    return 0;
}
/*在clodblacks的结果是：
int和long都可以接收10位数字
long long可以接收19位数字
*/
