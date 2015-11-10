#include <iostream>
#include <algorithm>
#define  MAXN 10

using namespace std;

int main( void )
{
    int n;
    int arrAy[MAXN];

    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> arrAy[i];
    sort( arrAy, arrAy + n );

    do
    {
        for ( int i = 0; i < n; i++ )
            cout << arrAy[i];
        cout << endl;
    }
    while ( next_permutation( arrAy, arrAy + n ) );

    return 0;
}
