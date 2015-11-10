#include <iostream>
#include <cstring>
#define  MAXN 400

using namespace std;

int main( void )
{
    int n;
    int arrAy[MAXN];

    while ( cin >> n ){
        int temp = n;
        memset( arrAy, 0, sizeof( arrAy ) );
        for ( int i = 2; n > 1; i++ ){
            if ( 0 == n % i ){
                arrAy[i]++;                     //求得每一个素数因子的个数
                n /= i;
                i = 1;
            }
        }
        int sum( 1 );
        for ( int i = 0; i < temp; i++ ){
            sum *= ( arrAy[i] + 1 );            //利用公式累乘计算所有的正约数个数
        }
        cout << sum << endl;
    }

    return 0;
}
