#include <stdio.h>

int main(void)
{
    int i = 3, j = 10;
    int temp;

    temp = i & j;//按位与，二进制位相同则该位为1
    printf("%d\n", temp);

    temp = i | j;//按位或，二进制有1则该位为1
    printf("%d\n", temp);

    printf("%d %d\n", ~i, ~j);//取反运算符

    temp = i ^ j;//按位异或
    printf("%d\n", temp);

    //temp = i << 1;
    printf("%d %d\n", j << 1, j >> 1);//<<按位左移，既在原数的基础上乘以2的n次方；按位右移，等价于在原数的基础上除以2的n次方。

    return 0;
}
