#include <stdio.h>

int main(void)
{
    char ch;
    int num_space, num_enter, num_other;

    num_space = num_enter = num_other = 0;
    while ((ch = getchar()) != '#')
    {
        if (' ' == ch)
            num_space++;
        else if ('\n' == ch)
            num_enter++;
        else
            num_other++;
    }
    printf("%d %d %d", num_space, num_enter, num_other);

    return 0;
}
