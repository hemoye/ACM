#include <stdio.h>

int main(void)
{
    int n, i, m, t;
    int num = 0;

    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        int flag = 1;
        m = i;
        while (m)
        {
            if (m % 10 == 7)
            {
                num++;
                flag = 0;
                break;
            }
            m /= 10;
        }
        if (flag && i % 7 == 0)
            num++;
    }
    printf("%d\n", num);

    return 0;
}
