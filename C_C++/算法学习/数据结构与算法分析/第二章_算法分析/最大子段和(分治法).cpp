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
    int mid = low + ( high - low ) / 2;                                 /**���η����**/
    int left_sum = Merge( arrAy, low, mid );
    int right_sum = Merge( arrAy, mid, high );
    int total_sum = left_sum > right_sum ? left_sum : right_sum;        /**total_sum������߻����ұߵĽϴ�ֵ**/
    int left( 0 ), right( 0 ), lsum( 0 ), rsum( 0 );

    for ( int i = mid - 1; i >= 0; i-- ){                               /**�����ߵ�����Ӷκ�**/
        left += arrAy[i];
        if ( left > lsum ){
            lsum = left;
        }
    }
    for ( int i = mid; i < high; i++ ){                                 /**����ұߵ�����Ӷκ�**/
        right += arrAy[i];
        if ( right > rsum ){
            rsum = right;
        }
    }
    rsum += lsum;                                                       /**�ϲ����ߵ�����Ӷκ�ֵ**/
    return total_sum > rsum ? total_sum : rsum;                         /**�ж������ߵ�ֵ�����ұߵ�ֵ��**/
}
