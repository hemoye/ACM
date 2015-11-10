#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];
    int i, flage = 1;

    while (gets(str) != NULL)
    {
        for (i = 0; i < strlen(str); i++)
            if (str[i-1] != '-' && str[i] == '-' && str[i+1] != '-')
                putchar(' ');
            else if (str[i] == '-' && str[i+1] != '-')
                printf(" null");
            else
            {
                if (str[i] == ' ' || str[i] == '-')
                    printf(" null");
                else
                    putchar(str[i]);
            }
            putchar('\n');
    }

    return 0;
}
