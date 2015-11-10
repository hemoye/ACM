#include <stdio.h>
#include <string.h>

int main(void)
{
    int sum, i, j;
    char str[3][1001] = {"CHOPPER", "NICO ROBIN", "MONKEY.D.LUFFY"};
    char ch[100];

    scanf("%d", &sum);

    ch[0] = getchar();

    for (i = 1; i <= sum; i++)
    {
        int flage = 0;

        gets(ch);

        for (j = 0; j < 3; j++)
            if (strcmp (str[j], ch) == 0)
                flage = 1;
        if (flage)
            printf("Case %d:\nYES\n", i);
        else
            printf("Case %d:\nNO\n", i);
    }


    return 0;
}
