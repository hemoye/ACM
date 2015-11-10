#include <stdio.h>
#include <string.h>

int main(void)
{
    int judge(char );

    char str[100];
    int i, j;

    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        if (str[0] == '@')
        {
            printf("NO\n");
            return 0;
        }
        if (!(str[i] == '.' || str[i] == '_' || str[i] == '@' || (judge(str[i]))))
        {
            printf("NO\n");
            return 0;
        }
        else
        {
            if (str[i] == '@' && (!(judge(str[i-1])) || !(judge(str[i+1]))))
            {
                printf("NO\n");
                return 0;
            }
            if (str[i] == '.' && (!(str[i+1] == 'c' && str[i+2] == 'o' && str[i+3] == 'm' && (i+4) == strlen(str))))
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");

    return 0;
}
int judge(char a)
{
    if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
        return 1;
    else
        return 0;
}
