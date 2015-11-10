#include <iostream>
#define  MAXN 40

using namespace std;

int main( void )
{
    int n;
    int arrAy[MAXN];
    while ( cin >> n ){
        arrAy[0] = 1;
        for ( int i = 1; i < n; i++ ){
            arrAy[i] = arrAy[i-1] * ( n - i ) / i;
        }
        for ( int i = 0; i < n; i++ ){
            cout << arrAy[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
