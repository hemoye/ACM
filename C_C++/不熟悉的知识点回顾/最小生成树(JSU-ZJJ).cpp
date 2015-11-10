#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 400;
const int INF = 0x3fffffff;

int n;
int arrAy[MAXN][MAXN];
bool vis[MAXN];

int Prim( void );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int T;
    scanf("%d", &T );
    while ( T-- ){
        scanf("%d", &n );
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 1; j <= n; j++ ){
                scanf("%d", &arrAy[i][j] );
                if ( !arrAy[i][j] ) arrAy[i][j] = INF;
            }
        }
        printf("%d\n", Prim() );
    }

    return 0;
}
int Prim( void )
{
    int ans(0);
    int count(0);
    for ( int i = 2; i <= n; i++ )  vis[i] = false;
    vis[1] = true;
    while ( count++ < n ){
        int mmin(INF);
        int e1(-1), e2(-1);
        for ( int i = 1; i <= n; i++ ){
            if ( vis[i] ){
                for ( int j = 1; j <= n; j++ ){
                    if ( !vis[j] && arrAy[i][j] < mmin ){
                        mmin = arrAy[i][j];
                        e1 = i;
                        e2 = j;
                    }
                }
            }
        }
        ans += arrAy[e1][e2];
        vis[e2] = true;
    }
    return ans;
}
