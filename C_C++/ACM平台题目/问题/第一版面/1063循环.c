#include <stdio.h>

int main(void)
{
    int n, i, k, a[10];

    while (scanf("%d", &n) != EOF)
    {
        int sum = 1;
        for (i = 0; i < 10; i++)
        {
            sum *= n;
            a[i] = sum % 10;
        }
        for (k = 1; k < 10; k++)
            if (a[0] == a[k] && a[1] == a[k+1])
            {
                printf("%d\n", k);
                break;
            }
    }

    return 0;
}
