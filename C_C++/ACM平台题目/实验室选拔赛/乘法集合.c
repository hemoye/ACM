#include <stdio.h>
#include <math.h>

int judge(char * , int );

int main(void)
{
    int i, j;
    char str[1001];

    scanf("%s", str);
    for (i = 111; i < 1000; i++)
        for (j = 11; j < 100; j++)
            if (judge(str, i) && judge(str, j) && judge(str, i * j))
            {
                printf("%5d\n", i);
                printf("X%4d\n", i);
                printf("-----\n", i);
                printf("%5d\n", i*j);
            }

    return 0;
}
int judge(char * str, int a)
{
    int i, z, j = 0, s[100] = {0};
    while (a)
    {
        s[j++] = a % 10;
        a /= 10;
    }
    for (i = 0; i < strlen(str); i++)
        for (z = 0; z < j; z++)
            if (str[i] - '0' == s[z])
                return 0;
    return 1;
}
