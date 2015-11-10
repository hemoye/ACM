/**问题描述：
    如果由正整数构成的集合X满足以下条件，我们称它为n~k特殊集
    1、集合X中的每个元素均不超过n，即1<=x<=n.
    2、集合X中所有的元素之和大于k
    3、集合X中不包含任意一对相邻的自然数
**/
#include <iostream>
#define  F( i, j ) ( f[(i)+1][(j)+1] )              /**用宏处理支持负数下标**/

using namespace std;

int f[200][500];                                    /**结果可能很大，需要用高精度**/

int main( void )
{
    int i, j, n, k;

    while ( cin >> n >> k ){
        for ( j = -1; j <= k; j++ ){                /**边界**/
            F( -1, j ) = F( 0, j ) = 0;
        }
        F( -1, -1 ) = F( 0, -1 ) = 1;
        for ( i = 1; i <= n; i++ ){
            for ( j = -1; j <= k; j++ ){            /**递推**/
                F( i, j ) = F( i - 1, j );
                if ( j - i < 0 ){
                    F( i, j ) += F( i - 2, -1 );
                }
                else {
                    F( i, j ) += F( i - 2, j - i );
                }
            }
        }
        cout << F( n, k ) << endl;
    }
    return 0;
}
