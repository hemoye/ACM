#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    long value,result[1000];
    long i, j, v, n;
    scanf ("%ld%ld",&v, &n);
    result[0] = 1;
    for (i = 1; i <= v; i ++)
    {
        scanf ("%ld", &value);
        for (j = value; j <= n; j ++)
        {
            result[j] = result[j] + result[j - value];
        }
        printf ("\n");
    }
    printf ("result = %ld\n", result[j - 1]);
}
