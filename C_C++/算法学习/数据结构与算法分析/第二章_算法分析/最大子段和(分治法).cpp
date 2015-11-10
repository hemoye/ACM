#include <iostream>
#define  MAXN 400

using namespace std;

int Merge( int * , int , int );

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
    cout << "Largest sub-segment and is : " << Merge( arrAy, 0, n ) << endl;

    return 0;
}
int Merge( int * arrAy, int low, int high )
{
    if ( 1 == high - low ){
        return arrAy[low];
    }
    int mid = low + ( high - low ) / 2;                                 /**分治法求解**/
    int left_sum = Merge( arrAy, low, mid );
    int right_sum = Merge( arrAy, mid, high );
    int total_sum = left_sum > right_sum ? left_sum : right_sum;        /**total_sum保存左边或者右边的较大值**/
    int left( 0 ), right( 0 ), lsum( 0 ), rsum( 0 );

    for ( int i = mid - 1; i >= 0; i-- ){                               /**求得左边的最大子段和**/
        left += arrAy[i];
        if ( left > lsum ){
            lsum = left;
        }
    }
    for ( int i = mid; i < high; i++ ){                                 /**求得右边的最大子段和**/
        right += arrAy[i];
        if ( right > rsum ){
            rsum = right;
        }
    }
    rsum += lsum;                                                       /**合并两边的最大子段和值**/
    return total_sum > rsum ? total_sum : rsum;                         /**判断是两边的值大还是右边的值大**/
}
