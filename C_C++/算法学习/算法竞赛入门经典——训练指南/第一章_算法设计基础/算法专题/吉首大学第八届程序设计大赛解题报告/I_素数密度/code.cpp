#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000000;
bool f[100009], ff[MAXN+4];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    unsigned L, R;
    int n(47004);
    memset( f, true, sizeof(f) );
    memset( ff, true, sizeof(ff) );
    f[1] = false;
    for ( int i = 2; i <= sqrt(n); i++ ){
        if ( f[i] ){
            for ( int j = i + i; j <= n; j += i ){
                f[j] = false;
            }
        }
    }
    while ( ~scanf("%u%u", &L, &R ) ){
        int ans(0);
        if ( R <= n ){
            for ( int i = L; i <= R; i++ ){
                if ( f[i] ){
                    ans++;
                }
            }
            printf("%d\n", ans );
            continue;
        }
        if ( L <= n ){
            for ( int i = L; i <= n; i++ ){
                if ( f[i] ){
                    ans++;
                }
            }
            L = n + 1;
        }
        for ( int i = 1; i <= n; i++ ){
            if ( f[i] ){
                int LL = L / i;
                int RR = R / i;
                for ( int j = LL; j <= RR; j++ ){
                    ff[i*j-L+1] = false;
                }
            }
        }
        for ( int i = 1; i <= R - L + 1; i++ ){
            if ( ff[i] ){
                ans++;
            }
        }
        printf("%d\n", ans );
    }

    return 0;
}
