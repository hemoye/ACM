#include <cstdio>
#define  MAXN 66

int start[MAXN], finish[MAXN];
long long Recur( int * , int , int );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int k(0);
    int n;

    while ( scanf("%d", &n ) != EOF ){
        if ( 0 == n )   break;
        for ( int i = 1; i <= n; i++ ){
            scanf("%d", start + i );
        }
        for ( int i = 1; i <= n; i++ ){
            scanf("%d", finish + i );
        }
        int m = n;
        long long ans(0);
        while ( m >= 1 && start[m] == finish[m] )   m--;
        if ( m >= 1 ){
            int other = 6 - start[m] - finish[m];
            ans = Recur( start, m - 1, other ) + Recur( finish, m - 1, other ) + 1;
        }
        printf("Case %d: %lld\n", ++k, ans );
    }

    return 0;
}
long long Recur( int * p, int i, int final )
{
    if ( 0 == i )   return 0;
    if ( p[i] == final )    return Recur( p, i - 1, final );
    return Recur( p, i - 1, 6 - p[i] - final ) + ( 1LL << ( i - 1 ) );
}
