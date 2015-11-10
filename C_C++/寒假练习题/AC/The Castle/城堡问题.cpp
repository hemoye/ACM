#include <iostream>

int main( void )
{
    using std::cout;
    using std::endl;

    int m, n;

    while ( std::cin >> m >> n )
    {
        int arrAy[m][n];

        for ( int i = 0; i < m; i++ )
            for ( int j = 0; j < n; j++ )
                std::cin >> arrAy[i][j];

    }

    return ;
}
