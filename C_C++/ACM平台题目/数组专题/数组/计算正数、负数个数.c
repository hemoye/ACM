#include <stdio.h>

int main(void)
{
    int a[20];
    int i = 0, j = 0, num1 = 0, num2 = 0, sum = 0;

    while (scanf("%d", &a[i++]) && a[i-1] != 0);
    for (j = 0; j < i - 1; j++)
    {
        if (a[j] > 0)
        {
            num1++;
            sum += a[j];
        }
        else
            num2++;
    }
    printf("%d %d %d\n", num1, (sum / num1), num2);

    return 0;
}
