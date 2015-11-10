#include <stdio.h>
int main(void)
{
    char c;
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;

    while (scanf("%c", &c) && (c != '\n'))
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            num1++;
        else if (c >= '0' && c <= '9')
            num2++;
        else if (c == ' ')
            num3++;
        else
            num4++;
    }

    printf("%d %d %d %d\n", num1, num2, num3, num4);

    return 0;
}
