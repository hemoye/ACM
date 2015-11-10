#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1004;
const int INF = 0x7fffffff;

int ans, m;
int arrAy[MAXN];
int x[MAXN], y[MAXN];
int mat[MAXN][MAXN];
int lowdit[MAXN];
bool vis[MAXN];

int dist( int x1, int y1, int x2, int y2 );
void Prim( void );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;
    scanf("%d", &n );
    for ( int i = 0; i < n; i++ ){
        scanf("%d", arrAy + i );
        arrAy[i] = arrAy[i] * arrAy[i];
    }
    scanf("%d", &m );
    for ( int i = 0; i < m; i++ ){
        scanf("%d%d", x + i, y + i );
    }
    for ( int i = 0; i < m; i++ ){
        for ( int j = i + 1; j < m; j++ ){
            mat[i][j] = mat[j][i] = dist( x[i], y[i], x[j], y[j] );
        }
    }
    Prim();
    int num(0);
    for ( int i = 0; i < n; i++ ){
        if ( arrAy[i] >= ans ){
            num++;
        }
    }
    printf("%d\n", num );

    return 0;
}
int dist( int x1, int y1, int x2, int y2 )
{
    return ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 );
}
void Prim( void )
{
    vis[0] = true;
    int k;
    for ( int i = 1; i < m; i++ )   lowdit[i] = mat[0][i];
    for ( int i = 1; i < m; i++ ){
        int Min = INF;
        for ( int j = 0; j < m; j++ ){
            if ( !vis[j] && Min > lowdit[j] ){
                k = j;
                Min = lowdit[j];
            }
        }
        vis[k] = true;
        if ( Min > ans )    ans = Min;
        for ( int j = 0; j < m; j++ ){
            if ( !vis[j] && lowdit[j] > mat[k][j] ){
                lowdit[j] = mat[k][j];
            }
        }
    }

    return ;
}
