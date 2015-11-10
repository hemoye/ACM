#include <stdio.h>

int i = 0;

int Hannuota(int n)
{
    if (1 == n)
        i++;
    else
    {
        Hannuota(n-1);
        i++;
        Hannuota(n-1);
    }
    return i;
}
int main(void)
{
    int n;

    scanf("%d", &n);

    printf("%d\n", Hannuota(n));

    return 0;
}
