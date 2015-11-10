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
        printf("%d込込\n", n);
    else
    {
        F(n-1);
        printf("%d細細\n", n);
    }

    return 0;
}
