#include <stdio.h>
int main(void)
{
    char str[100];
    int i;

    gets(str);

    if (str[0] == '_' || (str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
    {
        for (i = 1; i <= strlen(str); i++)
        {
            if (str[i] == '_' || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
                continue;
            else
                break;
        }
        if (i = strlen(str))
            printf("Yes\n");
        else
            printf("No\n");
    }
    else
        printf("No\n");

    return 0;
}
