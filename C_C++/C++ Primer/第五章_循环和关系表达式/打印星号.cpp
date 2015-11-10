#include <iostream>

int main( void )
{
    using namespace std;

    int time;

    cin  >> time;

    for ( int i = 0; i < time; i++ )
    {
        for ( int j = 1; j < time - i; j++ )
            cout << " ";
        for ( int x = 0; x <= i; x++ )
            cout << "*";
        cout << endl;
    }

    return 0;
}
