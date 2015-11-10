#include <iostream>

int main( void )
{
    using namespace std;

    const int MAX = 10;
    double arrAy[MAX];
    double total = 0;
    int count = 0, i = 0;

    while ( i < MAX && cin >> arrAy[i++] )
        total += arrAy[i-1];

    total /= ( i - 1 );

    for ( int j = 0; j < i; j++ )
        if ( arrAy[j] > total )
            count++;
    cout << total << endl
         << count << endl;

    return 0;
}
