#include <stdio.h>
#include <string.h>
#define MAX 1001

int main(void)
{
    char str[MAX], ch[MAX];
    int a[MAX], b[MAX];
    int i, j;

    scanf ("%s%s", str, ch);
    for (i = 0; i < strlen(str); i++)
        a[i] = str[i] - '0';
    for (j = 0; j < strlen(str); j++)
        b[i] = ch[i] - '0';


    return 0;
}
