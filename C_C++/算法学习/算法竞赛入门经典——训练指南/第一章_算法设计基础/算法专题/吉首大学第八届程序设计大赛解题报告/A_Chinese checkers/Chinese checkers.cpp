#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1004;
const int INF = 0x7fffffff;

struct Node {
    int pos1, pos2;
    int step;
} ;

int vis[MAXN][MAXN];

void Form( void )
{
    Node Next, pre;
    queue<Node> Q;
    vis[0][1] = 0;
    pre.pos1 = pre.step = 0;
    pre.pos2 = 1;
    Q.push( pre );
    while ( !Q.empty() ){
        Node Cur = Q.front();
        Q.pop();
        Next = Cur;
        if ( Next.pos1 + 1 != Next.pos2 ){
            Next.pos1++;
            Next.step++;
            if ( Next.pos2 < 1001 && vis[Next.pos1][Next.pos2] > Next.step ){
                vis[Next.pos1][Next.pos2] = Next.step;
                Q.push( Next );
            }
        }
        Next = Cur;
        Next.pos2++;
        Next.step++;
        if ( Next.pos2 < 1001 && vis[Next.pos1][Next.pos2] > Next.step ){
            Q.push( Next );
            vis[Next.pos1][Next.pos2] = Next.step;
        }
        Next = Cur;
        Next.pos2 = Cur.pos2 + Cur.pos2 - Cur.pos1;
        Next.pos1 = Cur.pos2;
        Next.step++;
        if ( Next.pos2 < 1001 && vis[Next.pos1][Next.pos2] > Next.step ){
            vis[Next.pos1][Next.pos2] = Next.step;
            Q.push( Next );
        }
    }

    return ;
}

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n, t;
    for ( int i = 0; i <= 1000; i++ ){
        for ( int j = 0; j <= 1000; j++ ){
            vis[i][j] = INF;
        }
    }
    Form();
    scanf("%d", &t );
    while ( t-- ){
        scanf("%d", &n );
        printf("%d\n", vis[n-2][n-1] );
    }

    return 0;
}
