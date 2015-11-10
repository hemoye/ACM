#include <iostream>
#include <cstring>
#define  MAXN 1000

int main( void )
{
    using namespace std;

    int n, num;
    int prime[MAXN];
    int vis[MAXN];

    while ( cin >> n ){
        num = 0;
        memset( vis, 0, sizeof( vis ) );
        for ( int i = 2; i <= n; i++ ){
            if ( !vis[i] ){
                prime[++num] = i;
                for ( int j = 2 * i; j <= n; j += i ){
                    vis[j] = 1;
                }
            }
        }
        for ( int i = 1; i <= num; i++ ){
            cout << prime[i] << endl;
        }
    }

    return 0;
}
