#include <stdio.h>
#define  MAX 20

int main( void )
{
    int x, a;
    char str[MAX];

    scanf("%d", &x);

    sprintf(str, "%d", x);//��һ������ת�����ַ���

    puts(str);

    sscanf(str, "%d", &a);//��һ���ַ���ת��������
    printf("->%d\n", a);

    return 0;
}
