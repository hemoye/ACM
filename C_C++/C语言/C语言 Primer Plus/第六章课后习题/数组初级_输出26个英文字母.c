#include <stdio.h>

int main(void)
{
    char ch[26];
    int i;

    for (i = 0; i < 26; i++)
        ch[i] = i + 65;

    for (i = 0; i < 26; i++)
        (i == 0) ? printf("%c", ch[i]) : printf("%c", ch[i]);
    printf("\n");

    return 0;
}
