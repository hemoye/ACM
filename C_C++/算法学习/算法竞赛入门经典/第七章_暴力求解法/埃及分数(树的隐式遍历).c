#include <stdio.h>

int main(void)
{
    int a,b,c;
    scanf("%d/%d", &a, &b );
    printf("%d/%d = ", a, b );
    while ( a != 1 )
    {
        c = b / a + 1;
        a = a * c - b;
        b = b * c;
        printf("1/%d + ", c );

        if ( ( b % a == 0 ) || ( a == 1 ) )
        {
            printf("1/%d\n", b/a);
            a = 1;
        }
    }
    return 0;
}
