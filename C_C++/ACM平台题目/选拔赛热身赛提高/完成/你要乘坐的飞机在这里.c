#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, go = 1, stay = 1;
    char str1[7], str2[7];

    scanf("%s%s", str1, str2);
    for (i = 0; i < strlen(str1); i++)
        go *= (str1[i] - 64);
    for (i = 0; i < strlen(str2); i++)
        stay *= (str2[i] - 64);

    if (go % 47 == stay % 47)
        printf("GO\n");
    else
        printf("STAY\n");

    return 0;
}
