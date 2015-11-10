#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 260;
using namespace std;

void Count( char * str, int len )
{
    int s1(0), s2(0);
    for ( int i = 0; i < len; i++ ){
        if ('0' == str[i])  s1++;
        else    s2++;
    }
    if (s1!=0&&s2!=0){
        printf("C");
        Count(str, len/2);
        Count(&str[len/2], len/2);
    }
    else if (s1)    printf("A");
    else    printf("B");
}

int main(int agrc, char *agrv[])
{
    char str[MAXN];
    int len;

    while (~scanf("%s", str)){
        Count(str, strlen(str));
        puts("");
    }

    return 0;
}
