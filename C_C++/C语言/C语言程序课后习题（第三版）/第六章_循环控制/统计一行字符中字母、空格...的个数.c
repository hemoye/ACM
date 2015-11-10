#include <stdio.h>
int main(void)
{
    char ch;
    int a = 0, b = 0, c = 0, d = 0;

    while ((ch = getchar()) != '\n')
    {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            a++;
        if (ch == ' ')
            b++;
        if (ch >= '0' && ch <= '9')
            c++;
        else
            d++;
    }
    printf("%d %d %d %d\n", a, b, c, d);
}
