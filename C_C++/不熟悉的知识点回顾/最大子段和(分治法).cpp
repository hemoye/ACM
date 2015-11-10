#include <iostream>
#define  MAXN 40

using namespace std;

int arrAy[MAXN];

int Merge( int , int );

int main( void )
{
    int n;

    cout << "Please enter the size of the array : ";
    cin >> n;
    cout << "Please enter the n elements : ";
    for ( int i = 0; i < n; i++ ){
        cin >> arrAy[i];
    }
    cout << "The largest sub-segment and is: " << Merge( 0, n ) << endl;

    return 0;
}
int Merge( int low, int high )
{
    if ( low == high - 1 ){
        return arrAy[low];
    }
    int mid = low + ( high - low ) / 2;
    int left = ( low, mid );
    int right = ( mid, high );
    int sum = left + right;
    int left_sum( 0 ), right_sum( 0 ), left_total( 0 ), right_total( 0 );

    for ( int i = mid - 1; i >= 0; i-- ){
        left_sum += arrAy[i];
        if ( left_sum > left_total ){
            left_total = left_sum;
        }
    }
    for ( int i = mid; i < high; i++ ){
        right_sum += arrAy[i];
        if ( right_sum > right_total ){
            right_total = right_sum;
        }
    }
    right_total += left_total;
    return sum > right_total ? sum : right_total;
}
