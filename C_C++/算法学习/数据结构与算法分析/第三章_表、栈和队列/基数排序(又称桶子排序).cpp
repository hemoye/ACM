#include <iostream>
#include <cstring>
#define  MAXN 40

using namespace std;

int MaxBit( int * , int );
void RadixSort( int * , int );

int main( void )
{
    int n;
    int data[MAXN];                                     /**������������**/
    int order[MAXN];                                    /**�洢��׺Ϊ1~9��Ԫ�صĸ���**/
    int temp[MAXN][MAXN];                               /**�洢Ԫ��**/

    memset( order, 0, sizeof( order ) );
    memset( temp, 0, sizeof( temp ) );

    cout << "Please enter the size of the array: ";
    cin >> n;
    cout << "Please enter n elements: ";
    for ( int i = 0; i < n; i++ ){
        cin >> data[i];
    }

    int x( 1 ), k( 0 );
    while ( x <= 100 ){                                 /**x����Ҫ��������ֵ����λ��**/
        for ( int i = 0; i < n; i++ ){
            int lsd = ( data[i] / x ) % 10;
            temp[lsd][order[lsd]] = data[i];
            order[lsd]++;
        }
        cout << "After reorder: ";
        for ( int i = 0; i < n; i++ ){
            if ( order[i] ){
                for ( int j = 0; j < order[i]; j++ ){
                    data[k++] = temp[i][j];
                    cout << data[k] << " ";
                }
            }
            order[i] = 0;
        }
        cout << endl;
        x *= 10;
        k = 0;
    }
    cout << "After sorting: ";
    for ( int i = 0; i < n; i++ ){
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
