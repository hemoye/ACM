/**问题描述：
        空间里有n个点Po,P1……Pn-1;你的任务是把它们配成n/2对（n为偶数）,
        使得每个点恰好在一个点对中。所有点对中两点的距离之和应尽量小.
**/
#include <iostream>
#include <cstring>
#define  MAXN 40

using namespace std;

int arrAy[MAXN], dis[MAXN];
int dp( int );

int main( void )
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ){
        cin >> arrAy[i];
    }
    dp( n );
    int Min( 0 );
    for ( int i = 0; i < n / 2; i++ ){
        Min += dis[i];
    }
    cout << Min << endl;

    return 0;
}
int dp( int n )
{
    if ( n <= 0 ){
        return 0;
    }
}
