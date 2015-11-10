#include <iostream>
#include <cstring>
#define  MAXN 101

using namespace std;

struct Node
{
    int x, y;
    int p, tt;
} ;

int m, n, t;
char map[2][MAXN][MAXN];
int  vis[2][MAXN][MAXN];
const int help[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs( int , int , int );

int main( void )
{
    int i, j, k;
    int a, b, c;
    int time;

    cin >> time;
    while ( time-- )
    {
        cin >> n >> m >> t;

        memset( vis, 0, sizeof( vis ) );
        for ( k = 0; k < 2; k++ )
        {
            for ( i = 0; i < n; i++ )
                for ( j = 0; j < m; j++ )
                {
                    cin >> map[k][i][j];
                    if ( 'S' == map[k][i][j] )
                    {
                        a = k;
                        b = i;
                        c = j;
                    }
                }
        }
        for ( i = 0; i < n; i++ )
            for ( j = 0; j < m; j++ )
                if ( map[0][i][j] == '#' && map[1][i][j] == '#' )
                    map[0][i][j] = map[1][i][j] = '*';
                else if ( map[0][i][j] == '#' && map[1][i][j] == '*' )
                    map[0][i][j] = map[1][i][j] = '*';
                else if ( map[0][i][j] == '*' && map[1][i][j] == '#' )
                    map[0][i][j] = map[1][i][j] = '*';

        bfs( a, b, c );
    }

    return 0;
}
void bfs( int a, int b, int c )
{
    Node Q[MAXN*MAXN];
    int front = 0, rear = 1;
    int i;

    Q[0].x = b;
    Q[0].y = c;
    Q[0].tt = t;
    Q[0].p = a;
    vis[a][b][c] = 1;
    while ( front < rear )
    {
        Node u = Q[front++];
        if ( map[u.p][u.x][u.y] == 'P' )
        {
            cout << "YES" << endl;
            return ;
        }
        for ( i = 0; i < 4; i++ )
        {
            Node v = u;
            v.x += help[i][0];
            v.y += help[i][1];
            v.tt--;
            if ( v.x >= 0 && v.y >= 0 && v.x < n && v.y < m && map[v.p][v.x][v.y]!='*' && !vis[v.p][v.x][v.y] && v.tt >= 0 )
            {
                if ( map[v.p][v.x][v.y] == '#' && !vis[v.p][v.x][v.y] )
                {
                    vis[v.p][v.x][v.y] = 0;
                    v.p = !u.p;
                }
                vis[v.p][v.x][v.y] = 1;
                Q[rear++] = v;
            }
        }
    }
    cout << "NO" << endl;
    return ;
}
