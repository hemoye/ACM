#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1004;
const int INF = 0x7fffffff;
bool vis[MAXN];
int lowdit[MAXN];
int arrAy[MAXN];
int x[MAXN], y[MAXN];
int mat[MAXN][MAXN];
int ans, n;

int dist( int x1, int y1, int x2, int y2 )
{
    return ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 );
}
void Prime( void )
{
    int k;
    vis[0] = true;
    for ( int i = 1; i < n; i++ ){
        lowdit[i] = mat[0][i];
    }
    for ( int i = 1; i < n; i++ ){
        int Min = INF;
        for ( int j = 0; j < n; j++ ){
            if ( !vis[j] && Min > lowdit[j] ){
                k = j;
                Min = lowdit[j];
            }
        }
        vis[k] = true;
        if ( Min > ans )    ans = Min;
        for ( int j = 0; j < n; j++ ){
            if ( !vis[j] && lowdit[j] > mat[k][j] ){
                lowdit[j] = mat[k][j];
            }
        }
    }
    return ;
}
int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int m;
    scanf("%d", &m );
    for( int i = 0; i < m; i++ ){
        scanf("%d", arrAy + i );
        arrAy[i] = arrAy[i] * arrAy[i];
    }
    scanf("%d", &n );
    for ( int i = 0; i < n; i++ ){
        scanf("%d%d", x + i, y + i );
    }
    for ( int i = 0; i < n; i++ ){
        for ( int j = i + 1; j < n; j++ ){
            mat[i][j] = mat[j][i] = dist( x[i], y[i], x[j], y[j] );
        }
    }
    Prime();
    int ret(0);
    for ( int i = 0; i < m; i++ ){
        if ( arrAy[i] >= ans ){
            ret++;
        }
    }
    printf("%d\n", ret );
}
