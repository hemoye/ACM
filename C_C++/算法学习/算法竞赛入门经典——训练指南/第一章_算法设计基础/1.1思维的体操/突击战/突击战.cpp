#include <cstdio>
#include <algorithm>
#define  MAXN 1004

using namespace std;

struct Job {
    int account;
    int need;
    bool operator < ( const Job & x ) const {
        return need > x.need;
    }
} ;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    Job arrAy[MAXN];
    int N, time(0);

    while ( scanf("%d", &N ) != EOF ){
       if ( 0 == N ){
           break;
       }
       for ( int i = 0; i < N; i++ ){
           scanf("%d%d", &arrAy[i].account, &arrAy[i].need );
       }
       sort( arrAy, arrAy + N );
       int s(0), ans(0);
       for ( int i = 0; i < N; i++ ){
            s += arrAy[i].account;
            ans = max( ans, s + arrAy[i].need );
       }
       printf("case %d: %d\n", ++time, ans );
    }

    return 0;
}
