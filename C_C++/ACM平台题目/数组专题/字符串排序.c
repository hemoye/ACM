#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[3][1000], ch[1000];
    int i, j;

    for (i = 0; i < 3; i++)
        scanf("%s", str[i]);
    for (i = 0; i < 3; i++)
        for (j = 0; j < 2 - i; j++)
            if (strcmp (str[j], str[j+1]) > 0)
            {
                strcpy (ch, str[j]);
                strcpy (str[j], str[j+1]);
                strcpy (str[j+1], ch);
            }
    for (i = 0; i < 3; i++)
        printf("%s\n", str[i]);

    return 0;
}
