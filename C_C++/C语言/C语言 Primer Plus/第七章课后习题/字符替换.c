#include <stdio.h>

int main(void)
{
    int num_replace = 0;
    char ch;

    while ((ch = getchar()) != '#')
    {
        if ('.' == ch)
        {
            printf("!");
            num_replace++;
        }
        else if ('!' == ch)
        {
            printf("!!");
            num_replace++;
        }
        else
            putchar(ch);
    }
    printf("\n�滻�Ĵ���Ϊ��%d\n", num_replace);

    return 0;
}
