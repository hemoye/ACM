#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define  MAXN 1004
using namespace std;

vector<int> gr[MAXN], nodes[MAXN];
int n, s, k, fa[MAXN];
bool covered[MAXN];

void dfs( int , int , int );
void dfs2( int , int , int );
int  solve( void );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int T;
    scanf("%d", &T );
    while ( T-- ){
        scanf("%d%d%d", &n, &s, &k );
        for ( int i = 0; i <= n; i++ ){
            gr[i].clear();
            nodes[i].clear();
        }
        for ( int i = 0; i < n - 1; i++ ){
            int a, b;
            scanf("%d%d", &a, &b );
            gr[a].push_back( b );
            gr[b].push_back( a );
        }
        dfs( s, -1, 0 );
        printf("%d\n", solve() );
    }

    return 0;
}
void dfs( int u, int f, int d )
{
    fa[u] = f;
    int nc = gr[u].size();
    if ( 1 == nc && d > k ){
        nodes[d].push_back(u);
    }
    for ( int i = 0; i < nc; i++ ){
        int v = gr[u][i];
        if ( v != f ){
            dfs( v, u, d + 1 );
        }
    }
    return ;
}
void dfs2( int u, int f, int d )
{
    covered[u] = true;
    int nc = gr[u].size();
    for ( int i = 0; i < nc; i++ ){
        int v = gr[u][i];
        if ( v != f && d < k ){
            dfs2( v, u, d + 1 );
        }
    }
    return ;
}
int solve( void )
{
    int ans = 0;
    memset( covered, false, sizeof( covered ) );
    for ( int d = n; d > k; d-- ){
        for ( int i = 0; i < nodes[d].size(); i++ ){
            int u = nodes[d][i];
            if ( !covered[u] ){
                int v = u;
                for ( int j = 0; j < k; j++ ){
                    v = fa[v];
                }
                dfs2( v, -1, 0 );
                ans++;
            }
        }
    }
    return ans;
}
