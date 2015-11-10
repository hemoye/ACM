#include <iostream>

using namespace std;

void Change( int m );

int main()
{
    int m;

    while ( cin >> m )
    {
        cout << m << "->";
        Change( m );
        cout << endl;
    }

    return 0;
}
void Change( int m )
{
    if ( m > 1 )
        Change( m / 2 );
    cout << ( m % 2 );

    return ;
}
