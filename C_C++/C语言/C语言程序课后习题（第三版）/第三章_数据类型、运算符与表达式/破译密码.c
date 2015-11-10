#include <stdio.h>
int main(void)
{
    int i;
    char c[10] = {"China"};

    for (i = 0; i < 5; i++)
        c[i] += 4;

    for (i = 0; i < 5; i++)
        printf("%c", c[i]);
    printf("\n");
}
