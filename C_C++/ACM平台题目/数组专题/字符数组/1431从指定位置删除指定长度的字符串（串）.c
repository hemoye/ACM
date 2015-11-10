#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, p, n;
    char str[1001];

    scanf("%s%d%d", str, &p, &n);
    if (p + n >= strlen(str))
    {
        printf("Illegal input\n");
        return 0;
    }
    for (i = p - 1; i < strlen(str) - n; i++)
        str[i] = str[i+n];
    str[i] = '\0';
    puts(str);

    return 0;
}
