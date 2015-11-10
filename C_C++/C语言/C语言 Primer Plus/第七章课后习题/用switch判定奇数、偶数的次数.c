#include <stdio.h>

int main(void)
{
    int n;
    int num_oushu = 0, num_jishu = 0;

    while (scanf("%d", &n) && n != 0)
    {
        n = n % 2;
        switch (n)
        {
        case 0 :
            num_oushu++;
            break;
        default :
            num_jishu++;
        }
    }
    printf("%d %d", num_oushu, num_jishu);

    return 0;
}
