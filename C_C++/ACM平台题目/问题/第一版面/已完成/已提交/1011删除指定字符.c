#include <stdio.h>

void del_char(char * c, char str[]);

int main(void)
{
    char ch, c, str[1000];

    scanf("%c", &ch);
    c = getchar();
    gets(str);

    del_char(ch, str);

    return 0;
}
void del_char(char * c, char str[])
{
    int i, j = 0;

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
            continue;
        str[j] = str[i];
        j++;
    }
    str[j] = '\0';

    puts(str);

    return 0;
}
