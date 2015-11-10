#include <iostream>
#include <cstring>
#define  MAXN 1000

using namespace std;

int prime[MAXN];
int arrAy[MAXN];
int cnt, n;

void InitPrime( void );
int  SquareRoot( void );

int main( void )
{
    int T;
    cin >> T;
    while ( T-- ){
        cin >> n;
        cnt = 0;
        InitPrime();
        cout << SquareRoot() << endl;
    }

    return 0;
}
void InitPrime( void )                              /**构建素数表**/
{
    int i, j;
    memset( arrAy, 0, sizeof( arrAy ) );
    for ( i = 2; i <= n; i++ ){
        if ( !arrAy[i] ){
            prime[cnt++] = i;
            for ( j = 2 * i; j <= n; j += i ){
                arrAy[j] = 1;
            }
        }
    }
    return ;
}
int SquareRoot( void )
{
    int num( 0 );
    int i, j;

    for ( i = 2; i <= n; i++ ){
        for ( j = 0; j < cnt; j++ ){
            if ( 0 == i % ( prime[j] * prime[j] ) ){
                break;
            }
        }
        if ( j == cnt ){
            num++;
        }
    }
    return num;
}
