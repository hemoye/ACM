#include <stdio.h>

int a[50];

void swap(int * a, int * b, int t)//交换两个数据的值
{
    t = *a;
    *a = *b;
    *b = t;
}

void search(int n, int pos, int m)
{
    int i, t;

    if(pos < 0)//作为结束递归的判定标志
        return ;

    swap(&a[pos], &a[n-m], t);//交换数组内部的值

    for(i=n-1; i>=pos; i--)
        printf("%d", a[i]);//打印每一组数据
    if (pos != 0)
        printf("，");
    swap(&a[n-m], &a[pos], t);//把数据交换回来
    m++;
    if(0 == n - m + 1)//判断是不是已经到了最后的m位数
        search(n-1, pos-1, n-pos);
    else
        search(n, pos, m);
}
int main(void)
{
    int i, m;

    for(i=0; i<6; i++)
        scanf("%d", &a[i]);//输入数组中的值

    scanf("%d", &m);//输入每一组数据的数字个数

    search(6, 6 - m, m);//函数调用

    return 0;
}

