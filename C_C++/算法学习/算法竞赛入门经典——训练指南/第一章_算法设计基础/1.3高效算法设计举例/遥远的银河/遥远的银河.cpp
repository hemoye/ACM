#include <cstdio>
#include <algorithm>
#define  MAXN 104
using namespace std;

struct Point {
    int x, y;
    bool operator < ( const Point & rhs ) const {
        return x < rhs.x;
    }
} ;

Point P[MAXN];
int n, m, y[MAXN], on[MAXN], on2[MAXN], left[MAXN];

int solve( void )
{
    sort( P, P + n );
    sort( y, y + n );
    m = unique( y, y + n ) - y;         //所有不同的y坐标的个数
    if ( m <= 2 ){                      //最多两种不同的y时可以全部在边界上
        return n;
    }
    int ans(0);
    for ( int a = 0; a < m; a++ ){
        for ( int b= a + 1; b < m; b++ ){
            int ymin = y[a], ymax = y[b];       //计算上下边界分别为ymin和ymax时的解

            int k(0);
            for ( int i = 0; i < n; i++ ){
                if ( 0 == i || P[i].x != P[i-1].x ){
                    k++;
                    on[k] = on2[k] = 0;
                    left[k] = k == 0 ? 0 : left[k-1] + on2[k-1] - on[k-1];
                }
                if ( P[i].y > ymin && P[i].y < ymax ){
                    on[k]++;
                }
                if ( P[i].y >= ymin && P[i].y <= ymax ){
                    on2[k]++;
                }
            }
            if ( k <= 2 ){              //最多两种不同的x
                return n;
            }

            int M(0);
            for ( int j = 1; j <= k; j++ ){
                ans = max( ans, left[j] + on2[j] + M );
                M = max( M, on[j] - left[j] );
            }
        }
    }
    return ans;
}
int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int kase(0);
    while ( ~scanf("%d", &n ) && n ){
        for ( int i = 0; i < n; i++ ){
            scanf("%d%d", &P[i].x, &P[i].y );
            y[i] = P[i].y;
        }
        printf("Case %d: %d\n", ++kase, solve() );
    }

    return 0;
}
