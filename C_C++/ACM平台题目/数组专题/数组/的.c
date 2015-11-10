#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j;
    char str[101];

    while (scanf("%s", str) != EOF)
    {
        for (i = 0; i < strlen(str); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'c')
                putchar('2');
            else if (str[i] >= 'd' && str[i] <= 'f')
                putchar('3');
            else   if (str[i] >= 'g' && str[i] <= 'i')
                putchar('4');
            else   if (str[i] >= 'j' && str[i] <= 'l')
                putchar('5');
            else  if (str[i] >= 'm' && str[i] <= 'o')
                putchar('6');
            else   if (str[i] >= 'p' && str[i] <= 's')
                putchar('7');
            else  if (str[i] >= 't' && str[i] <= 'v')
                putchar('8');
            else  if (str[i] >= 'w' && str[i] <= 'z')
                putchar('9');
            else   if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 33;
                putchar(str[i]);
            }
            else   if (str[i] == 'Z')
                putchar('a');
            else
                putchar(str[i]);
        }
    }

    return 0;
}
