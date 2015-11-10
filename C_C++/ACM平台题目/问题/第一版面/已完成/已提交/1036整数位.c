#include <stdio.h>
int main(void)
{
    unsigned n, m;
    int i = 0, j = 0;

    scanf("%u", &n);
    m = n;
    while (m)
    {
        m /= 10;
        i++;
    }
    printf("%d ", i);
    if (i == 5)
    {
        printf("%d %d %d %d %d ", n%10, (n%100)/10, (n%1000)/100, (n%10000)/1000, n/10000);
        printf("%d %d %d %d %d\n", n/10000,(n%10000)/1000,(n%1000)/100,(n%100)/10,n%10);
    }
    else if (i == 4)
    {
        printf("%d %d %d %d ", n%10, (n%100)/10, (n%1000)/100, n/1000);
        printf("%d %d %d %d\n", n/1000,(n%1000)/100,(n%100)/10,n%10);
    }
    else if (i ==3)
    {
        printf("%d %d %d ", n/100, (n/10)%10, n%10);
        printf("%d %d %d\n", n%10, (n/10)%10, n/100);
    }
    else if (i == 2)
        printf("%d %d %d %d\n", n/10, n%10, n%10, n/10);
    else
        printf("%d %d\n", n, n);

    return 0;
}
