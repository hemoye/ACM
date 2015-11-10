#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[1000], str2[1000];
    int i, j;

    while (scanf("%s%s", str1, str2) != EOF)
    {
        int a[1000] = {0}, b[1000] = {0}, c[1000] = {0};
        int num1 = 0, num2 = 0, len1, len2;

        for (i = 0; i < strlen(str1); i++)
        {
            num1++;
            a[i] = str1[i] - '0';
            if (str1[i+1] == '.')
                break;
        }
        //for (i = num1 + 1; )
        for (i = 0; i < strlen(str2); i++)
        {
            num2++;
            b[i] = str2[i] - '0';
            if (str2[i+1] == '.')
                break;
        }
        for (i = 0; i < num1; i++)
            for (j = 0; j < num2; j++)
                c[i+j+1] += a[i] * b[i];
        for (i = num1 + num2 - 1; i > 0; i--)
            while (c[i] > 9)
            {
                c[i-1] += c[i] / 10;
                c[i] %= 10;
            }
        if (c[0])
            printf("%d", c[0]);
        for (i = 1; i < num1 + num2; i++)
            printf("%d", c[i]);
        printf("\n");
    }

    return 0;
}
