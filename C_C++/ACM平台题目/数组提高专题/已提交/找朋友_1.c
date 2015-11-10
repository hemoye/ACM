#include <stdio.h>
#include <string.h>
#define B "boyfriend"
#define G "girlfriend"

int main(void)
{
    char c, str[1001], ch[1001];
    int i, flage;

    while (scanf("%s", str) != EOF)
    {
        flage = 1;
        c = getchar();
        c = getchar();
        if (c == 'b')
        {
            //printf("%c", c);
            for (i = 0; i < strlen(str); i++)
                if (str[i] == 'g')
                {
                    //printf("haha\n");
                    strncpy (ch, str+i, 10);
                    ch[10] = '\0';
                    //printf("%s", ch);
                    if (flage && strcmp(G, ch) == 0)
                    {
                        printf("%d\n", i);
                        flage = 0;
                    }
                }
        }
        else
        {
            for (i = 0; i < strlen(str); i++)
                if (str[i] == 'b')
                {
                    //printf("heihei\n");
                    strncpy (ch, str+i, 9);
                    ch[9] = '\0';
                    //printf("%s", ch);
                    if (flage && strcmp(B, ch) == 0)
                    {
                        printf("%d\n", i);
                        flage = 0;
                    }
                }
        }

    }

    return 0;
}
