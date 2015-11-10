#include <stdio.h>
float M(float x)
{
    int f1 = 1, f2 = 2, f3;
    int i;

    if (1 == x)
        f3 = f1;
    else if (2 == x)
        f3 = f2;
    else
    {
        for (i = 2; i < x; i++)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
    }

    return f3;
}

int main(void)
{
    float i, sum = 0;

    for (i = 1; i <= 20; i++)
        sum += M(i+1) / M(i);

    printf("%.2f\n", sum);
}
/*在clodblacks里面输出的结果是
*****************************
          32.66
*****************************
总结：定义函数应该与主函数里面所需求的
      数据类型一致
*/
