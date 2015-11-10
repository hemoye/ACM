#include <stdio.h>

int qiuhe(int );

int main(void)
{
    int n = 100;

    printf("%d\n", qiuhe(n));

    return 0;
}
int qiuhe(int n)
{
    if (1 == n)
       return 1;
    else
       return n + qiuhe(n-1);
}
