#include <stdio.h>
int main(void)
{
    int n, num, extra;

    scanf("%d", &n);
    num = 10 * n / 3;
    extra = 10 * n % 3;

    printf("%d %d\n", num, extra);

    return 0;
}
