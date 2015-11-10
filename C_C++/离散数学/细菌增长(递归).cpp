#include <iostream>

int Rise( int n );

int main( void )
{
    using std::cout;
    using std::endl;

    int n;

    std::cin >> n;
    cout << Rise( n ) << endl;

    return 0;
}
int Rise( int n )
{
    if ( 1 == n )
        return 5;
    else
        return 2 * Rise( n - 1 );
}
