#include <stdio.h>

int main(void)
{
    int num_space = 0, num_num = 0, num_char = 0, num_other = 0;
    char ch;

    while (scanf("%c", &ch) != EOF)
    {
        if (' ' == ch)
            num_space++;
        else if (ch >= '0' && ch <= '9')
            num_num++;
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            num_char++;
        else
            num_other++;
    }
    printf("%d %d %d %d\n", num_space, num_num, num_char, num_other);

    return 0;
}
