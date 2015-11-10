#include <iostream>
#define  MAXN 40

using namespace std;

int Search( const int * , int , int , int );

int main( void )
{
    int n, x;
    int arrAy[MAXN];

    cin >> n;
    for ( int i = 0; i < n; i++ ){
        cin >> arrAy[i];
    }
    cin >> x;
    int num = Search( arrAy, 0, n, x );
    if ( -1 == num ){
        cout << "Search filed, no such number in the array." << endl;
    }
    else {
        cout << "Search successed, the number of " << x << " was located at " << num << endl;
    }

    return 0;
}
int Search( const int * arrAy, int low, int high, int x )
{
    if ( low == high ){
        return -1;
    }
    else {
        int mid = low + ( high - low ) / 2;
        if ( arrAy[mid] == x ){
            return mid + 1;
        }
        else if ( arrAy[mid] > x ){
            Search( arrAy, low, mid, x );
        }
        else {
            Search( arrAy, mid, high, x );
        }
    }
}
