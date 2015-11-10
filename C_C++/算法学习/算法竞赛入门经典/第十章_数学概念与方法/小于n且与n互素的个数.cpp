#include <iostream>
#include <cstring>
#include <cmath>
#define  MAXN 4000

using namespace std;
int arrAy[MAXN];

int  Euler_Phi( int );           /**ŷ������**/
void Phi_Table( int );          /**���**/

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
ŷ�������
���ܣ����1~n����Ԫ�ص�ŷ������ֵ
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
            m = m / i * ( i - 1 );              /**ŷ����ʽ: ŷ��ֵ(x) = x * (1-1/P1) * (1-1/p2) * ...(1-1/Pn)**/
            while ( 0 == n % i ){               /**�ù�ʽ��������֮��:x*((p-1)/p)**/
                n /= i;
            }
        }
    }
    if ( n > 1 ){                               /**��n����1��ʱ�򣬼������ʱ��nҲ��ԭ�����������ӣ����Ի�Ҫ����һ��ŷ����ֵ**/
        m = m / n * ( n - 1 );
    }
    return m;
}
