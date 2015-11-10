#include <stdio.h>

int main(void)
{
    int a = 4;
    int * p = &a;

    printf("%d的地址是:%p, %p\n", a, &a, p);
    printf("指向%d的指针的地址是：%p\n", a, &p);

    return 0;
}
