#include <iostream>
#include <cstring>
#include <cmath>
#define  MAXN 4000

using namespace std;
int arrAy[MAXN];

int  Euler_Phi( int );           /**欧拉函数**/
void Phi_Table( int );          /**打表**/

int main( void )
{
    int n;
    while ( cin >> n ){
        Phi_Table( n );
        cout << Euler_Phi( n ) << endl;
        cout << arrAy[n] << endl;
    }
}
/**
欧拉打表函数
功能：求出1~n所有元素的欧拉函数值
**/
void Phi_Table( int n )
{
    memset( arrAy, 0, sizeof( arrAy ) );
    arrAy[0] = 1;
    for ( int i = 1; i <= n; i++ ){
        if ( !arrAy[i] ){
            for ( int j = i; j <= n; j += i ){
                if ( !arrAy[j] ){
                    arrAy[j] = j;
                }
                arrAy[j] = arrAy[j] / i * ( i - 1 );
            }
        }
    }
    return ;
}
int Euler_Phi( int n )
{
    int m = n;
    int k = ( int )sqrt( double( n ) + 0.5 );

    for ( int i = 2; i <= k; i++ ){
        if ( 0 == n % i ){
            m = m / i * ( i - 1 );              /**欧拉公式: 欧拉值(x) = x * (1-1/P1) * (1-1/p2) * ...(1-1/Pn)**/
            while ( 0 == n % i ){               /**该公式经过变形之后即:x*((p-1)/p)**/
                n /= i;
            }
        }
    }
    if ( n > 1 ){                               /**在n大于1的时候，即代表此时的n也是原数的质数因子，所以还要进行一次欧拉求值**/
        m = m / n * ( n - 1 );
    }
    return m;
}
