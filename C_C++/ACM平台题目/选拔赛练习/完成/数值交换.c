#include <stdio.h>

int main(void)
{
    void Exchange(int * a, int * b);//函数声明

    int first, last, index, sum;//定义变量

    scanf("%d", &sum);//输入测试数据的组数

    for (index = 1; index <= sum; index++)
    {
        scanf("%d %d", &first, &last);//输入测试数据
        Exchange(&first, &last);//调用函数

        printf("Case %d: %d %d\n", index, first, last);//输出互换后的值
    }

    return 0;
}
void Exchange(int * a, int * b)//定义函数
//功能：用指针互换两个整形变量的值
{
    int temp;

    temp = *a;//a就是指针变量，a保存的就是frist的地址，*a等价于first的值
    *a = *b;
    *b = temp;
}
/*
总结：1、指针就是地址，地址就是指针
      2、地址就是内存单位的编号
      3、指针变量是有存放地址的变量
      4、指针和指针变量是两个不同的概念
      5、但是要注意，通常我们叙述时会把指针变量简称指针
         实际上他们不一样
*/
