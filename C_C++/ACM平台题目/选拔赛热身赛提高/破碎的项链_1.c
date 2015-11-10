#include <stdio.h>

int main(void)
{
    int i, j, t, sum, num, len;
    char str[1001];
    //memset(str, '\0', 1000);

    scanf("%d\n", &len);

    gets(str);
    //puts(str);
    for (i = num = 0; i < len; i++)
    {
        t = (0 == i) ? (len - 1) : (i - 1);
        sum = 0;
        j = i;
        if ('r' == str[i])
        {
            while (!('b' == str[j++]))
            {
                sum++;
                j %= len;
                if (sum == len)
                {
                    printf("%d\n", sum);
                    return 0;
                }
            }
        }
        else if ('b' == str[i])
        {
            while (!('r' == str[j++]))
            {
                sum++;
                j %= len;
                if (sum == len)
                {
                    printf("%d\n", sum);
                    return 0;
                }
            }
        }
        j = t;
        if ('r' == str[t])
        {
            while (!('b' == str[j--]))
            {
                sum++;
                if (-1 == j)
                    j = len - 1;
                if (sum == len)
                {
                    printf("%d\n", sum);
                    return 0;
                }
            }
        }
        else if ('b' == str[t])
        {
            while (!('r' == str[j--]))
            {
                sum++;
                if (-1 == j)
                    j = len - 1;
                if (sum == len)
                {
                    printf("%d\n", sum);
                    return 0;
                }
            }
        }
        if (num < sum)
            num = sum;
    }
    printf("%d", num);

    return 0;
}
