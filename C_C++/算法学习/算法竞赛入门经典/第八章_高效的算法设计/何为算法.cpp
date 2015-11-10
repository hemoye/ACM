#include <iostream>
#define  MAXN 100000

using namespace std;

int main( void )
{
    unsigned N, M;
    unsigned n, m, k;
    long long arrAy[MAXN];

    while ( cin >> N )
    {
        arrAy[0] = 0;
        for ( int i = 1; i <= N; i++ )
        {
            cin >> n;
            arrAy[i] = arrAy[i-1] + n;
        }
        cin >> k;
        for ( int i = 0; i < k; i++ )
        {
            cin >> m >> n;
            cout << arrAy[n] - arrAy[m-1] << endl;
        }
    }

    return 0;
}
