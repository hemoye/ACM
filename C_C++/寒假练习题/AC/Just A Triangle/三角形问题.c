#include <stdio.h>

int main( void )
{
    int time;
    int a, b, c;

    scanf("%d", &time);

    while ( time-- )
    {
        scanf("%d%d%d", &a, &b, &c);

        if (a == b || b == c || a == c)
            printf("prefect\n");
        else
        {
            if ( a * a + b * b == c * c || c * c + b * b == a * a || a * a + c * c == b * b)
                printf("good\n");
            else
                printf("just a triangle\n");
        }
    }

    return 0;
}
