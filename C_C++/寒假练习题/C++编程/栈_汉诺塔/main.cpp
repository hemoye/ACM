#include <iostream>

using namespace std;

int Hannuota( int , char , char , char );
int time = 0;

int main()
{
    int n;

    while ( cin >> n )
    {
        cout << Hannuota( n, 'A', 'B', 'C' ) << endl;
        time = 0;
    }

    return 0;
}
int Hannuota( int n, char A, char B, char C )
{
    if ( 1 == n )
        time++;
    else
    {
        Hannuota ( n - 1, A, C, B );
        time++;
        Hannuota ( n - 1, A, B, C );
    }
    return time;
}
