#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define  MAXN 40
#define  REP( i, n ) for ( int i = 0; i < n; i++ )

using namespace std;

int n;
char posp[MAXN][MAXN][MAXN];
char view[6][MAXN][MAXN];

char read_char( void )
{
    char ch;
    while ( true ){
        ch = getchar();
        if ( ch >= 'A' && ch <= 'Z' || ch == '.' ){
            return ch;
        }
    }
}
void get( int k, int i, int j, int len, int &x, int &y, int &z )
{
    if ( 0 == k ){
        x = len;
        y = j;
        z = i;
    }
    if ( 1 == k ){
        x = len;
        y = j;
        z = i;
    }
    if ( 2 == k ){
        x = len;
        y = j;
        z = i;
    }
    if ( 3 == k ){
        x = len;
        y = j;
        z = i;
    }
    if ( 4 == k ){
        x = len;
        y = j;
        z = i;
    }
    if ( 5 == k ){
        x = len;
        y = j;
        z = i;
    }
}

int main( int agrc, char *agrv[] )
{


    return 0;
}
