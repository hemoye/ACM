#include <stdio.h>

int main(void)
{
    int i = 3, j = 10;
    int temp;

    temp = i & j;//��λ�룬������λ��ͬ���λΪ1
    printf("%d\n", temp);

    temp = i | j;//��λ�򣬶�������1���λΪ1
    printf("%d\n", temp);

    printf("%d %d\n", ~i, ~j);//ȡ�������

    temp = i ^ j;//��λ���
    printf("%d\n", temp);

    //temp = i << 1;
    printf("%d %d\n", j << 1, j >> 1);//<<��λ���ƣ�����ԭ���Ļ����ϳ���2��n�η�����λ���ƣ��ȼ�����ԭ���Ļ����ϳ���2��n�η���

    return 0;
}
