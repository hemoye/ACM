#include <iostream>

using namespace std;
double Count( int , int );

int main( void )
{
    int m, n;

    while ( cin >> m >> n && m * n )
        cout << Count( m, n ) << endl;

    return 0;
}
double Count( int x, int y )
{
    return 2.0 * x * y / ( x + y );
}
