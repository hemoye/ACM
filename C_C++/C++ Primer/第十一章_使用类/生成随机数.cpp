#include <iostream>
#include <cstdlib>
#include <ctime>

int main( void )
{
    srand( ( unsigned int )time( NULL ) );

    using std::cout;
    using std::endl;

    int t;

    for ( int i = 0; i < 20; i++ )
    {
        t = rand() % 6 + 1;
        cout << t << endl;
    }

    return 0;
}
