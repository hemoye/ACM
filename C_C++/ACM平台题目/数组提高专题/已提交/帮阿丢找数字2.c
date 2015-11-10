#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000], ch[1000];
    int i, j, k = 0;

    while (gets(str) != NULL)
    {
        int num = 0;
        for (i = 0; i < strlen(str); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
                ch[num++] = str[i];


        }
        printf("%\n");
    }

    return 0;
}
