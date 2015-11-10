#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];
    int i, j, sum;
    int z = 0;

    while (gets(str) != NULL)
    {
        sum = 0;

        for (i = 0; i < strlen(str); i++)
            if (str[i] >= '0' && str[i] <= '9')
                sum += str[i];

        printf("Case #%d:\nsum = %d\n", ++z, sum);
    }

    return 0;
}
