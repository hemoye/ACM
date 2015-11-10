#include <stdio.h>

int judge(int n)
{
    if (1 == n)
        return 1;
    else if (2 == n)
        return 2;
    return judge(n - 1) + judge(n - 2);
}

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        if (0 == n)
            break;
        printf("%d\n", judge(n));
    }

    return 0;
}
