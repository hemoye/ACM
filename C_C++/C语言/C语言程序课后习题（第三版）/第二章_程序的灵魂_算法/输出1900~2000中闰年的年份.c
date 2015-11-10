#include <stdio.h>
int main(void)
{
    int i;

    for (i = 1900; i <= 2000; i++)
    {
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
        printf("%d\n", i);
    }
}
