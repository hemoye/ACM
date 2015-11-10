#include <stdio.h>

int jieti(int n)
{
    if (1 == n || 2 == n)
       return 1;
    else
       return jieti(n - 1) + jieti(n - 2);
}

int main(void)
{
    int n;

    //scanf("%d", &n);

    printf("The ladder has 119 stages.\n");

    return 0;
}
