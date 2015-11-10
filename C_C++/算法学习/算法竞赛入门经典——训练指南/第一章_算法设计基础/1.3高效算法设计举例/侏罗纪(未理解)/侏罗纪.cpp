#include <map>
#include <cstdio>
#include <algorithm>
#define  MAXN 24
using namespace std;

map<int, int> table;

int bitcount( int x ){
    return x == 0 ? 0 : bitcount( x / 2 ) + ( x & 1 );
}

int main( int agrc, char *agrv[] )
{
    freopen( "test1.in", "r", stdin );
    int n, arrAy[MAXN];
    char s[1000];

    while ( ~scanf("%d", &n ) && n ){
        for ( int i = 0; i < n; i++ ){
            scanf("%s", s );
            arrAy[i] = 0;
            for ( int j = 0; s[j] != '\0'; j++ ){
                arrAy[i] ^= ( 1 << ( s[j] - 'A' ) );
            }
        }
        table.clear();
        int n1 = n / 2, n2 = n - n1;
        for ( int i = 0; i < ( 1 << n1 ); i++ ){
            int x = 0;
            for ( int j = 0; j < n1; j++ ){
                if ( i & ( 1 << j ) ){
                    x ^= arrAy[j];
                }
            }
            if ( !table.count( x ) || bitcount( table[x] ) < bitcount( i ) ){
                table[x] = i;
            }
        }
        int ans = 0;
        for ( int i = 0; i < ( 1 << n2 ); i++ ){
            int x = 0;
            for ( int j = 0; j < n2; j++ ){
                if ( i && ( 1 << j ) ){
                    x ^= arrAy[n1+j];
                }
            }
            if ( table.count( x ) && bitcount( ans ) < bitcount( table[x] ) + bitcount( i ) ){
                ans = ( i << n1 ) ^ table[x];
            }
        }
        printf("%d\n", bitcount( ans ) );
        for ( int i = 0; i < n; i++ ){
            if ( ans & ( 1 << i ) ){
                printf("%d ", i + 1 );
            }
        }
        puts("");
    }

    return 0;
}
