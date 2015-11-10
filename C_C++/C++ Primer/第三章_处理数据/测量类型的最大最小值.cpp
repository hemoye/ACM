#include <iostream>
#include <climits>

int main( void )
{
    using namespace std;

    int n_max = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;

    cout << sizeof( int ) << endl;
    cout << sizeof n_short << endl;
    cout << sizeof n_long << endl;

    cout << n_max << endl;
    cout << n_short << endl;
    cout << n_long << endl;
    cout << INT_MIN << endl;

    return 0;
}
