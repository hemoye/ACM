#include <iostream>

using namespace std;
int Cubes( int );

int main( void )
{
    int n, m;

    cin  >> n;

    for ( int i = 6; i <= n; i++ )
    {
        for ( int a = 2; a <= n; a++ )
            for ( int b = a + 1; b < n; b++ )
                for ( int c = b + 1; c < n; c++ )
                    if ( Cubes( i ) == Cubes( a ) + Cubes( b ) + Cubes( c ) )
                    {
                        cout << "Cube = " << i << "," << " Triple = "
                             << "(" << a << "," << b << "," << c << ")" << endl;
                    }
    }

    return 0;
}
int Cubes( int x )
{
    return x * x * x;
}
