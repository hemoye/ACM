#include <stdio.h>

int main(void)
{
    char i, j, c;

    scanf("%c", &j);
    for (i = 'A'; i <= j; i++)
    {
        for (c = j; c > i; c--)
            printf(" ");
        for (c = 'A'; c <= i; c++)
            printf("%c", c);
        for (c -= 2; c >= 'A'; c--)
            printf("%c", c);
        printf("\n");
    }

    return 0;
}
