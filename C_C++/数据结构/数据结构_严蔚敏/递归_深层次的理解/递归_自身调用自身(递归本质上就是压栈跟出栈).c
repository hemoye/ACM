#include <stdio.h>

void F(int );

int main(void)
{
    F(4);

    return 0;
}
void F(int n)
{
    if (n == 1)
        printf("%d����\n", n);
    else
    {
        F(n-1);
        printf("%d�ٺ�\n", n);
    }

    return 0;
}
