#include <iostream>

int main( void )
{
    using namespace std;

    unsigned m, n;

    while ( cin >> m >> n )
    {
        if ( -1 == m && -1 == n )
            break;

        char arrAy[m][m];
        int  count = 0, total = 0;

        for ( int i = 0; i < m; i++ )
        {
            for ( int j = 0; j < m; j++ )
                cin >> arrAy[i][j];
            for ( int j = 0; j < m; j++ )
                if ( '#' == arrAy[i][j] )
                {
                    count++;
                    break;
                }
        }

        for ( int i = 0; i < m; i++ )
        {
            int num = 0;
            for ( int j = 0; j < m; j++ )
                if ( '#' == arrAy[j][i] )
                    num++;
            if ( num > 1 )
                count = count - num + 1;
        }

        for ( int i = 1; i <= count - n + 1; i++ )
            total += i;

        cout << total << endl;
    }

    return 0;
}
