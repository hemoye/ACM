#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, len1, len2;
    char ch, str[1001], str1[500], str2[500];

    scanf("%s", str);
    for (i = len1 = len2 = 0; i < strlen(str); i++)
        if (0 == i % 2)
            str1[len1++] = str[i];
        else
            str2[len2++] = str[i];
    str1[len1] = str2[len2] = '\0';

    for (i = 0; i < len1 - 1; i++)
        for (j = 0; j < len1 - 1 - i; j++)
            if (str1[j] > str1[j+1])
            {
                ch = str1[j];
                str1[j] = str1[j+1];
                str1[j+1] = ch;
            }
    for (i = 0; i < len1 - 1; i++)
        for (j = 0; j < len1 - 1 - i; j++)
            if (str2[j] < str2[j+1])
            {
                ch = str2[j];
                str2[j] = str2[j+1];
                str2[j+1] = ch;
            }
    printf("%s%s\n", str1, str2);

    return 0;
}
