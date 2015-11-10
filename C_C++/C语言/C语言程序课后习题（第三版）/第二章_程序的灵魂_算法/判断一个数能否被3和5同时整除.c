#include <stdio.h>
int main(void)
{
    int s;

    scanf("%d", &s);
    if (0 == s % 5 && 0 == s % 3)
        printf("YES\n");
    else
        printf("NO\n");
}
