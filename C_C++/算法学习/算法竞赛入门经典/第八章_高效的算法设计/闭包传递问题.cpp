#include <stdio.h>
#include <cstring>
#define  MAXN 500

using namespace std;

int arrAy[MAXN];
void Warshall( int );

int main( void )
{

    int n, m, k;
    int a, b;

    cin >> k;

    while ( k-- ){
        memset( arrAy, 0, sizeof( arrAy ) );
        cin >> m >> n;
        for ( int i = 1; i <= n; i++ ){
            cin >> a >> b;
            arrAy[a][b] = arrAy[b][a] = 1;
        }
        Warshall( n + 1 );
    }

    return 0;
}
void Warshall( int num )
{

}
