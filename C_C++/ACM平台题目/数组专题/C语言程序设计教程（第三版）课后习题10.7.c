#include <stdio.h>
#include <string.h>

int main(void)
{
    void fuzhi(char str[], int, int);

    int i, n, m;
    char str[1000];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%c", &str[i]);

    str[i] = getchar();
    scanf("%d", &m);

    fuzhi(str, n, m);

    return 0;
}
void fuzhi(char str[], int n, int m)
{
    char ch[1000];
    int i, j = 0;

    for (i = m; i <= n; i++)
        ch[j++] = str[i];
    ch[j] = '\0';

    puts(ch);

    return 0;
}
