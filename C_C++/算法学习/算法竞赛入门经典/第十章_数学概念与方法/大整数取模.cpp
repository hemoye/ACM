#include <iostream>

using namespace std;

int main( void )
{
    string n;
    int m;

    while ( cin >> n >> m ){
        int ans( 0 );
        int len = n.length();
        for ( int i = 0; i < len; i++ ){
            ans = ( int )( ( ( long long ) ans * 10 + n[i] - '0' ) % m );
        }
        cout << ans << endl;
    }

    return 0;
}
