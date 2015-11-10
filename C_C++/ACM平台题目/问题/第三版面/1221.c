#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];
    int i;

    while (gets(str) != NULL)
        for (i = 0; i < strlen(str); i++)
        {
            if (str[i] == '<')
                printf("&lt;");
            else if (str[i] == '>')
                printf("&gt;");
            else if (str[i] == ' ')
                printf("&nbsp");
            else
                putchar(str[i]);
        }

    return 0;
}
