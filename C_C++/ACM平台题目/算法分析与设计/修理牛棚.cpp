#include <iostream>
#include <algorithm>
#define  MAXN 240

using namespace std;

int main( void )
{
    int board, num, length;

    while ( cin >> board >> length >> num ){
        int arrAy[MAXN];
        int dis[MAXN];

        for ( int i = 0; i < num; i++ ){
            cin >> arrAy[i];
        }
        sort( arrAy, arrAy + num );
        for ( int i = 0; i < num - 1; i++ ){
            dis[i] = arrAy[i+1] - arrAy[i];
        }
        sort( dis, dis + num - 1 );
        int sum = arrAy[num-1] - arrAy[0] + 1;
        for ( int i = 1; i < board; i++ ){
            sum = sum - dis[num-i-1] + 1;
        }
        cout << sum << endl;
    }
    return 0;
}
