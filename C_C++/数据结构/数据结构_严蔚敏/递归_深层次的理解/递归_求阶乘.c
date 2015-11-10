#include <stdio.h>

int jiecheng(int n)
{
    if (0 == n || 1 == n)
       return 1;
    else
       return n * jiecheng(n-1);
}
int main(void)
{
    int n = 5;

    printf("%d\n", jiecheng(n));

    return 0;
}
