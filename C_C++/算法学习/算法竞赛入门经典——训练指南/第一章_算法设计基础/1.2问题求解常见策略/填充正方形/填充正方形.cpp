#include <cstdio>
#include <cstring>
#define  MAXN 40

char grid[MAXN][MAXN];
int n;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int T;
    scanf("%d", &T );
    for ( int k = 1; k <= T; k++ ){
        memset( grid, '#', sizeof( grid ) );
        scanf("%d", &n );
        for ( int i = 1; i <= n; i++ )  scanf("%s", grid[i] );
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 0; j < n; j++ ){
                if ( '.' == grid[i][j] ){
                    for ( char ch = 'A'; ch <= 'Z'; ch++ ){
                        bool ok = true;
                        if ( grid[i-1][j] == ch )   ok = false;
                        if ( grid[i+1][j] == ch )   ok = false;
                        if ( grid[i][j+1] == ch )   ok = false;
                        if ( j > 0 && grid[i][j-1] == ch )  ok = false;
                        if ( ok ){
                            grid[i][j] = ch ;
                            break;
                        }
                    }
                }
            }
        }
        printf("Case %d:\n", k );
        for ( int i = 1; i <= n; i++ )   puts( grid[i] );
    }

    return 0;
}
