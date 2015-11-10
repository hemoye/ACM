#include <stdio.h>

int Ackerman(int m, int n);

int main(void)
{
    int m, n;

    scanf("%d%d", &m, &n);

    printf("%d\n", Ackerman(m, n));

    return 0;
}
int Ackerman(int m, int n)
{
    if (0 == m)
        return n + 1;
    if (m != 0 && 0 == n)
        Ackerman(m - 1, 1);
    if (m != 0 && n != 0)
        Ackerman(m - 1, Ackerman(m, n - 1));
}
