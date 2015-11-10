#include <iostream>
#include <cstring>
#define  MAXN 40

int Cmp_Max( int , int );                           /**求较大值**/

int main( void )
{
    using namespace std;

    int n;
    int arrAy[MAXN][MAXN], dis[MAXN][MAXN];

    memset( dis, 0, sizeof( dis ) );

    while ( cin >> n ){
        for ( int i = 0; i < n; i++ ){              /**输入n层数据**/
            for ( int j = 0; j <= i; j++ ){
                cin >> arrAy[i][j];
            }
        }
        for ( int i = 0; i < n; i++ ){              /**将最底层的数据复制给和数组**/
            dis[n-1][i] = arrAy[n-1][i];
        }
        for ( int i = n - 2; i >= 0; i-- ){         /**利用公式求值**/
            for ( int j = 0; j <= i; j++ ){
                dis[i][j] = arrAy[i][j] + Cmp_Max( dis[i+1][j], dis[i+1][j+1] );
            }
        }
        cout << dis[0][0] << endl;
    }

    return 0;
}
int Cmp_Max( int a, int b )
{
    return a > b ? a : b;
}
