#include <iostream>
#include <cstring>
#define  MAXN 40

using namespace std;

void Radix_Sort( int * , int );

int main( void )
{
    int n;
    int arrAy[MAXN];

    cout << "Please enter the size of the array : ";
    cin >> n;
    cout << "Please enter the n elements : ";
    for ( int i = 0; i < n; i++ ){
        cin >> arrAy[i];
    }
    Radix_Sort( arrAy, n );
    cout << "After sorting: ";
    for ( int i = 0; i < n; i++ ){
        cout << arrAy[i] << " ";
    }
    cout << endl;

    return 0;
}
void Radix_Sort( int * arrAy, int n )
{
    int temp[MAXN][MAXN];
    int num[MAXN];

    memset( temp, 0, sizeof( temp ) );
    memset( num, 0, sizeof( num ) );

    int x( 1 ), k( 0 );
    while ( x <= 100 ){
        for ( int i = 0; i < n; i++ ){
            int remainder = ( arrAy[i] / x ) % 10;      /**个位、十位、百位...的数字大小**/
            temp[remainder][num[remainder]] = arrAy[i];
            num[remainder]++;
        }
        for ( int i = 0; i < 10; i++ ){                 /**有1~9(共十个)编号的桶子**/
            if ( num[i] ){
                for ( int j = 0; j < num[i]; j++ ){
                    arrAy[k++] = temp[i][j];
                }
                num[i] = 0;
            }
        }
        x *= 10;                                        /**由个位向十位、百位递增**/
        k = 0;                                          /**元素全部复制回原空间之后，k必须重置为0，以备下次继续复制**/
    }
    return ;
}
