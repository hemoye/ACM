#include <stdio.h>

int main(void)
{
    int a = 4;
    int * p = &a;

    printf("%d�ĵ�ַ��:%p, %p\n", a, &a, p);
    printf("ָ��%d��ָ��ĵ�ַ�ǣ�%p\n", a, &p);

    return 0;
}
