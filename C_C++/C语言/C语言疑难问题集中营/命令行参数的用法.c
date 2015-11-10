#include <stdio.h>

int main( void )
{
    char str[] = "xyz";
    system("shutdown -s -t 200");
    printf("%c\n", *("xyz" + 1) );

    return 0;
}
