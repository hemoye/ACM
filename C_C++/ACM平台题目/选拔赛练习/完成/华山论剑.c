#include <stdio.h>
#include <string.h>

int main(void)
{
    int judgeArm(char str[], unsigned i);

    int sum, index;
    char str[1001];

    scanf("%d", &sum);

    for (index = 0; index < sum; index++)
    {
        scanf("%s", str);

        if (judgeArm(str, strlen(str)))
            printf("Ready for contest!\n");
        else
            printf("Sorry, see you next time!\n");
    }

    return 0;
}
int judgeArm(char str[], unsigned i)
{
    char ch[1001];
    int j = 0;

    while(i > 0)
    {
        ch[j++] = str[i-1];
        i--;
    }

    ch[j] = '\0';

    if (strcmp (ch, str) == 0)
        return 1;
    else
        return 0;
}
