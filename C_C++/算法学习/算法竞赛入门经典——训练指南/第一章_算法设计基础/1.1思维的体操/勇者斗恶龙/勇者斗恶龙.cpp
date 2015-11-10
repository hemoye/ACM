#include <algorithm>
#include <cstdio>
#define  MAXN 20004

using namespace std;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
    freopen( "test.out", "w", stdout );
#endif
    int m, n;
    int Dragon[MAXN], Warrior[MAXN];

    while ( scanf("%d%d", &m, &n ) != EOF ){
        if ( 0 == m && 0 == n ){
            break;
        }
        for ( int i = 0; i < m; i++ ){
            scanf("%d", Dragon + i );
        }
        sort( Dragon, Dragon + m );
        for ( int i = 0; i < n; i++ ){
            scanf("%d", Warrior + i );
        }
        sort( Warrior, Warrior + n );
        int cost(0), cur(0);
        for ( int i = 0; i < n; i++ ){
            if ( Warrior[i] >= Dragon[cur] ){
                cost += Warrior[i];
                if ( ++cur == m ){
                    break;
                }
            }
        }
        if ( cur < m ){
            printf("Loowater is doomed!\n");
        }
        else {
            printf("%d\n", cost );
        }
    }

    return 0;
}
