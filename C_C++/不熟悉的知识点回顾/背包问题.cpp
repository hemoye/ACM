#include <iostream>
#include <cstring>
#define  MAXN 40

struct Node
{
    int volume;
    int weight;
} ;

using namespace std;
int dp( int , int );
Node test[MAXN];
int d[MAXN];

int main( void )
{
    int num, limit;

    cin >> num >> limit;
    for ( int i = 0; i < num; i++ ){
        cin >> test[i].volume >> test[i].weight;
    }
    memset( d, -1, sizeof( d ) );

    cout << dp( limit, num ) << endl;

    return 0;
}
int dp( int limit, int num )
{
    int &ans = d[limit];
    if ( -1 != ans ){
        return ans;
    }
    ans = 0;
    for ( int i = 1; i <= limit; i++ ){
        for ( int j = 0; j < num; j++ ){
            if ( i >= test[j].volume ){
                int temp = dp( i - test[j].volume, num ) + test[j].weight;
                ans = ans > temp ? ans : temp;
            }
        }
    }
    return ans;
}
