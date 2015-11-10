#include <stdio.h>
int main(void)
{
    char str1[100], str2[100];
    int i, j;
    int m = 0, flag;

    gets(str1);
    scanf("%s", str2);

    for (i = 0; i < strlen(str1); i++)
    {
        flag = 0;
        for (j = 0; j < strlen(str2); j++)
        {
            if (str1[i] == str2[j])
                flag = 1;
        }
        if (0 == flag)
        {
            str1[m] = str1[i];
            m++;
        }
    }
    str1[m] = '\0';

    puts(str1);

    return 0;
}
