#include <iostream>
#include <cstring>
#define  MAXN 40

int Cmp_Max( int , int );                           /**��ϴ�ֵ**/

int main( void )
{
    using namespace std;

    int n;
    int arrAy[MAXN][MAXN], dis[MAXN][MAXN];

    memset( dis, 0, sizeof( dis ) );

    while ( cin >> n ){
        for ( int i = 0; i < n; i++ ){              /**����n������**/
            for ( int j = 0; j <= i; j++ ){
                cin >> arrAy[i][j];
            }
        }
        for ( int i = 0; i < n; i++ ){              /**����ײ�����ݸ��Ƹ�������**/
            dis[n-1][i] = arrAy[n-1][i];
        }
        for ( int i = n - 2; i >= 0; i-- ){         /**���ù�ʽ��ֵ**/
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
