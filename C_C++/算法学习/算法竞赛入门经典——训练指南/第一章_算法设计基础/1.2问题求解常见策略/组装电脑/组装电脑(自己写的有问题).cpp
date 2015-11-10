#include <cstdio>
#include <string>
#include <cstring>
#define  MAXN 1004
using namespace std;

struct Component {
    char ty[40];
    int price[10];
    int quality[10];
    int m;
} comp[MAXN];

int cnt;
int n, b;
void Push( char * , int & , int & );
bool Judge( int );

int main( int agcr, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int T;
    scanf("%d", &T );
    for ( int k = 0; k < T; k++ ){
        cnt = 0;
        int p, q;
        int maxq(0);
        char type[40], name[40];
        scanf("%d%d", &n, &b );
        for ( int i = 0; i < n; i++ ){
            scanf("%s%s%d%d", type, name, &p, &q );
            Push( type, p, q );
            maxq = max( maxq, q );
        }
        int L = 0, R = maxq;
        while ( L < R ){
            printf("%d\n", L );
            int M = L + ( R - L + 1 ) / 2;
            if ( Judge( M ) )   L = M;
            else   R = M - 1;
        }
        printf("%d\n", L );
    }

    return 0;
}
void Push( char * s, int &p, int &q )
{
    int i;
    for ( i = 0; i < cnt; i++ ){
        if ( 0 == strcmp( s, comp[i].ty ) ){
            int &x = comp[i].m;
            comp[i].price[x] = p;
            comp[i].quality[x] = q;
            x++;
            return ;
        }
    }
    comp[i].m = 0;
    int &x = comp[i].m;
    comp[i].price[x] = p;
    comp[i].quality[x] = q;
    x++;
    return ;
}
bool Judge( int q )
{
    int sum = 0;
    for ( int i = 0; i < cnt; i++ ){
        int cheapest = b + 1;
        for ( int j = 0; j < comp[i].m; j++ ){
            if ( comp[i].quality[j] >= q )  cheapest = min( cheapest, comp[i].price[j] );
        }
        if ( cheapest == b + 1 )    return false;
        sum += cheapest;
        if ( sum > b )  return false;
    }
    return true;
}
