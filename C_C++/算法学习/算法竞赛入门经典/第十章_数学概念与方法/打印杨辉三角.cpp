#include <iostream>
#include <cstring>
#define  MAXN 40

int main( void )
{
    using namespace std;
    int n;
    int arrAy[MAXN][MAXN];

    while ( cin >> n ){
        memset( arrAy, 0, sizeof( arrAy ) );
        for ( int i = 0; i < n; i++ ){
            arrAy[i][0] = 1;
            for ( int j = 1; j <= i; j++ ){
                arrAy[i][j] = arrAy[i-1][j] + arrAy[i-1][j-1];
            }
        }
        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < n - i - 1; j++ ){
                cout << " ";
            }
            for ( int j = 0; j <= i; j++ ){
                cout << arrAy[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
