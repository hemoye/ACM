#include <iostream>

using namespace std;

int Gcd( int , int );

int main( void )
{
    int m, n;

    cout << "Please enter two number: ";
    cin >> m >> n;
    cout << "The greatest common divisor of " << m << " and " << n
        << " is " << Gcd( m, n ) << endl;

    return 0;
}
int Gcd( int m, int n )
{
    while ( n ){
        int t = m % n;
        m = n;
        n = t;
    }
    return m;
}
