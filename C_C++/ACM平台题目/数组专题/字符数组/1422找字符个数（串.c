#include <stdio.h>
#include <stdio.h>

int main(void)
{
    int i, n;
    char ch, str[1001];

    scanf("%s%d", str, &n);

    if (0 == n)
    {
        puts(str);
        return 0;
    }
    for (i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
        if ((i+1) % n == 0)
            puts("");
    }
    puts("");

    return 0;
}
