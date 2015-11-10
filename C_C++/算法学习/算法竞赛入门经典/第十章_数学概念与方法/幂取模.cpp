#include <iostream>

int Pow_mod( int , int , int );

int main( void )
{
    using namespace std;

    int a, m, n;
    while ( cin >> a >> n >> m ){
        int ans = 1;
        for ( int i = 0; i < n; i++ ){
            ans = ( int )( ( ( long long ) ans * a % m ) );
        }
        cout << ans << endl;
        cout << Pow_mod( a, n, m ) << endl;
    }

    return 0;
}
/**分治法求解**/
int Pow_mod( int a, int n, int m )
{
    if ( n > 0 ){
        int x = Pow_mod( a, n / 2, m );
        long long ans = ( long long ) x * x % m;
        if ( 1 == n % 2 ){
            ans = ans * a % m;
        }
        return ( int ) ans;
    }
}
