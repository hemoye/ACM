#include <iostream>
#include <cstring>
#define  INF 32767
#define  MAXN 40

using namespace std;
int d[MAXN], Coins[MAXN];
int V;

int dp( int );

int main( void )
{
    int S;

    cin >> V >> S;
    memset( d, -1, sizeof( d ) );
    for ( int i = 0; i < V; i++ ){
        cin >> Coins[i];
    }
    cout << dp( S ) << endl;

    return 0;
}
int dp( int S )
{
    int &ans = d[S];
    if ( ans >= 0 ){
        return ans;
    }
    ans = 0;
    for ( int i = 0; i< V; i++ ){
        if ( S >= Coins[i] ){
            int temp = dp( S - Coins[i] ) + 1;
            ans = ans > temp ? ans : temp;
        }
    }
    return ans;
}
