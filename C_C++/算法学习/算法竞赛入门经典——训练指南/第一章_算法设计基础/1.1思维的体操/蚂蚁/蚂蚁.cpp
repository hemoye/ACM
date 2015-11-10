#include <cstdio>
#include <algorithm>
#define  MAXN 10004
using namespace std;

struct Ant {
    int id;
    int p;
    int d;
    bool operator < ( const Ant &a ) const {
        return p < a.p;
    }
} before[MAXN], after[MAXN];

const char Name[][10] = { "L", "Turning", "R" };
int order[MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
    freopen( "test.out", "w", stdout );
#endif
    int K;
    scanf("%d", &K );
    for ( int Kase = 1; Kase <= K; Kase++ ){
        int L, T, n;
        scanf("%d %d %d", &L, &T, &n );
        for ( int i = 0; i < n; i++ ){
            int p, d;
            char c;
            scanf("%d %c", &p, &c );
            d = ( 'L' == c ? -1 : 1 );
            before[i] = ( Ant ) { i, p, d };
            after[i] = ( Ant ) { 0, p + T * d, d };
        }
        printf("Case #%d:\n", Kase );
        sort( before, before + n );
        for ( int i = 0; i < n; i++ ){
            order[before[i].id] = i;
        }
        sort( after, after + n );
        for ( int i = 0; i < n - 1; i++ ){
            if ( after[i].p == after[i+1].p ){
                after[i].d = after[i+1].d = 0;
            }
        }
        for ( int i = 0; i < n; i++ ){
            int a = order[i];
            if ( after[a].p < 0 || after[a].p > L ){
                printf("Fell off\n");
            }
            else {
                printf("%d %s\n", after[a].p, Name[after[a].d+1] );
            }
        }
    }

    return 0;
}
