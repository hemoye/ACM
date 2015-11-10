#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001];
    int i;

    gets(str);
    for (i = 0; i < strlen(str); i++)
        if (str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            printf("%c", str[i]);
        else
            puts("");
    puts("");

    return 0;
}
