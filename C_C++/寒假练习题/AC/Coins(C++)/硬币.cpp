#include <iostream>

int main( void )
{
    using namespace std;

    const int MAX = 100000;
    int m, n;

    while ( cin >> m >> n && m != 0 && n != 0 )
    {
        int temp[MAX], total = 0, count = 0;

        for ( int i = 0; i < 2 * m; i++ )
            cin >> temp[i];

        for ( int i = 1; i < 2 * m; i++ )
            for ( int j = 0; j < 2 * m - i; j++ )
                if ( temp[j] < temp[j+1] )
                {
                    count = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = count;
                }

        for ( int i = 0; i < m; i++ )
            if ( total + temp[i] < n )
                total += temp[i];

        cout << total << endl;
    }

    return 0;
}
