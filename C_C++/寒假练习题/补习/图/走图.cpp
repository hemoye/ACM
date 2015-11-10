#include <iostream>
#include <cstring>
#include <cstdlib>
#define N 101

using namespace std;

char map[2][N][N];
int vis[2][N][N], n, m, time;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
struct Node
{
    int x, y, z, tim;
};
Node q[N*N];
void bfs(int z, int x, int y)
{
    int front = 0, rear = 1;
    Node u, v;
    u.x = x;
    u.y = y;
    u.z = z;
    u.tim = time;
    vis[z][x][y] = 1;
    q[0] = u;
    while( front < rear )
    {
        u = q[front++];
        if( map[u.z][u.x][u.y] == 'P' )
        {
            cout << "YES" << endl;
            return;
        }
        int i;
        for (i = 0; i < 4; i ++)
        {
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];
            v.z = u.z;
            v.tim = u.tim - 1;
            if ( v.x >= 0 && v.y >= 0 && v.x < n && v.y < m && map[v.z][v.x][v.y]!='*' && !vis[v.z][v.x][v.y] && v.tim >= 0 )
            {
                if ( map[v.z][v.x][v.y] == '#' && !vis[v.z][v.x][v.y] )
                {
                    vis[v.z][v.x][v.y] = 0;
                    v.z = !u.z;
                }
                vis[v.z][v.x][v.y] = 1;
                q[rear++] = v;
            }
        }
    }
    cout << "NO" << endl;
}
int main(void)
{
    int T, i, j, k;
    int x, y, z;
    cin >> T;
    while ( T -- )
    {
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> time;
        for (i = 0; i < 2; i ++)
            for (j = 0; j < n; j ++)
                for (k = 0; k < m; k ++)
                {
                    cin >> map[i][j][k];
                    if ( map[i][j][k] == 'S' )
                    {
                        x = i;
                        y = j;
                        z = k;
                    }
                }
        for(i = 0; i < n; i ++)
            for(j = 0; j < m; j ++)
            {
                if( map[0][i][j] == '#' && map[1][i][j]=='#' )
                {
                    map[0][i][j] = '*';
                    map[1][i][j] = '*';
                }
                if( map[0][i][j] == '*' && map[1][i][j]=='#' )
                {
                    map[0][i][j] = '*';
                    map[1][i][j] = '*';
                }
                if( map[0][i][j] == '#' && map[1][i][j]=='*' )
                {
                    map[0][i][j] = '*';
                    map[1][i][j] = '*';
                }
            }
        bfs(x, y, z);
    }
    return 0;
}
