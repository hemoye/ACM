#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001], ch[1001];
    int i, j, z, flage;

    while (gets(str) != NULL)
    {
        for (i = z = 0; i < strlen(str); i++)
        {
            flage = 1;
            for (j = 0; j < i; j++)
                if (str[i] == str[j])
                    flage = 0;
            if (flage)
                putchar(str[i]);
        }
        printf("\n\n");

        for (i = z = 0; i < strlen(str); i++)
            for (j = i + 1; j < strlen(str); j++)
                if (str[i] == str[j])
                    ch[z++] = str[i];

        ch[z] = '\0';
        //puts(ch);
        for (i = 0; i < z; i++)
        {
            flage = 1;
            for (j = 0; j < i; j++)
                if (ch[i] == ch[j])
                    flage = 0;
            if (flage)
                putchar(ch[i]);
        }
        printf("\n");
    }

    return 0;
}
