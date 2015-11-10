#include <stdio.h>
#include <string.h>
#define  MAX 10+1

int main( void )
{
    char x[MAX];
    char HH[MAX], MM[MAX], SS[MAX];

    fgets(x, MAX, stdin);

    sscanf(x, "%[0-9]:%[0-9]:%[0-9]", &HH, &MM, &SS);
    //特别值得注意的是，sscanf是从字符串中读出字符，有一个需要读出的字符形式控制说明，而且有一个读出的结束标志，此时的标志就是:

    printf("%s, %s, %s\n", HH, MM, SS);

    return 0;
}
