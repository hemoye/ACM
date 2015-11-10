#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[100], str2[100], str3[100], str4[100];

    scanf("%s %s %s", str1, str2, str3);
    if (strcmp(str1, str2) > 0)
    {
        strcpy(str4, str1);
        strcpy(str1, str2);
        strcpy(str2, str4);
    }

    if (strcmp(str1, str3) > 0)
    {
        strcpy(str4, str1);
        strcpy(str1, str3);
        strcpy(str3, str4);
    }

    if (strcmp(str2, str3) > 0)
    {
        strcpy(str4, str2);
        strcpy(str2, str3);
        strcpy(str3, str4);
    }

    printf("%s %s %s", str1, str2, str3);

    return 0;
}
