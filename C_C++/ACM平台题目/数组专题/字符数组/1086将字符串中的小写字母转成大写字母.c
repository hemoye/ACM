#include <stdio.h>
#include <string.h>

void change(char * str)
{
    int i;
    for (i = 0; i < strlen(str); i++)
        if (str[i] >= 'a' && str[i] <= 'z')
           str[i] -= 32;
    puts(str);

    return ;
}

int main(void)
{
    char str[1001];

    gets(str);
    change(str);

    return 0;
}
