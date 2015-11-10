#include <iostream>
#include <cstdlib>
#define  MAX 4000

int main( void )
{
    using std::cout;
    using std::endl;

    int n, i, j;

    while ( std::cin >> n )
    {
        if ( 0 == n )
            break;
        int str[MAX] = {1};
        for ( i = 2; i <= n; i++ )
        {
            int temp = 0;
            for ( j = 0; j < MAX; j++ )
            {
                int s = i * str[j] + temp;
                str[j] = s % 10;
                temp = s / 10;
            }
        }
        for ( j = MAX - 1; !str[j]; j-- );

        while ( j >= 0 )
            cout << str[j--];
        cout << endl;
    }

    return 0;
}
