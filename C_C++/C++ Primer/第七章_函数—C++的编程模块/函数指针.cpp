#include <iostream>

using namespace std;
double Cude( int );
double Count( int );
void estimate( int line, double ( *pf ) ( int ) );

int main( void )
{
    int m;

    cin  >> m;

    estimate( m, Cude );
    estimate( m, Count );

    return 0;
}
double Cude( int m )
{
    return m * m * m;
}
double Count( int m )
{
    return m + m + m;
}
void estimate( int line, double ( *pf ) ( int ) )
{
    cout << "The program taken " << ( *pf )( line ) << " hours." << endl;
}
