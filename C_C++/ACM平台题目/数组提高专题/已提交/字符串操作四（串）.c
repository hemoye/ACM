#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000], ch[1000];
    int i, num;

    while (gets(str) != NULL)
    {
        num = 0;
        for (i = 0; i < 1000; i++)
            ch[i] = '0';
        for (i = 0; i < strlen(str); i++)
            if (str[i] == '.')
            {
                ch[i] = str[i];
                num++;
                if (i == strlen(str) - 1)
                {
                    ch[i+2] = '0';
                    num += 2;
                }
                else if (i < strlen(str) - 2)
                {
                    ch[i+1] = str[i+1];
                    ch[i+2] = str[i+2];
                    num += 2;
                }
                break;
            }
            else
            {
                ch[i] = str[i];
                num++;
            }
        if (i == strlen(str))
        {
            ch[i] = '.';
            ch[i+1] = '0';
            ch[i+2] = '0';
            num += 3;
        }
        ch[num] = '\0';

        puts(ch);
    }

    return 0;
}
