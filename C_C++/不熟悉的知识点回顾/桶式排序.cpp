#include <iostream>
#include <cstring>
#define  MAXN 40

using namespace std;

void Radix_Sort( int * , int );

int main( void )
{
    int n;
    int arrAy[MAXN];

    cout << "Please enter the size of array: ";
    cin >> n;
    cout << "Please enter the n elements: ";
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
    int num[MAXN];
    int temp[MAXN][MAXN];

    memset( num, 0, sizeof( num ) );
    memset( temp, 0, sizeof( temp ) );

    int x( 1 ), k( 0 );
    while ( x <= 100 ){
        for ( int i = 0; i < n; i++ ){
            int remainder = ( arrAy[i] / x ) % 10;
            temp[remainder][num[remainder]] = arrAy[i];
            num[remainder]++;
        }
        for ( int i = 0; i < 10; i++ ){
            if ( num[i] ){
                for ( int j = 0; j < num[i]; j++ ){
                    arrAy[k++] = temp[i][j];
                }
            num[i] = 0;
            }
        }
        k = 0;
        x *= 10;
    }
    return ;
}
