#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int x, y;
    int dist;
} ;

const int MAXN = 204;
int n, m, ans;
int pos_x, pos_y;
int mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y)
{
    queue<Node> Q;
    Node t;
    t.x = x; t.y = y; t.dist = 0;
    vis[x][y] = true;
    Q.push(t);

    while (!Q.empty()){
        t = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++){
            Node v, u = t;
            if (u.x == pos_x && u.y == pos_y){
                printf("%d\n", u.dist);
                return ;
            }
            v.x = u.x + dx[i]; v.y = u.y + dy[i];
            if (v.x > 0 && v.x <= n && v.y > 0 && v.y <= m && !vis[v.x][v.y]){
                if (mat[v.x][v.y]){
                    v.dist = u.dist + 1;
                    // while (mat[v.x][v.y] && !vis[v.x][v.y]){
                        if (dy[i]){
                            v.y = v.y + dy[i] * mat[v.x][v.y];
                            if (v.y <= 0) v.y = 1;
                            else if (v.y > m) v.y = m;
                        }
                        else {
                            v.x = v.x + dx[i] * mat[v.x][v.y];
                            if (v.x <= 0) v.x = 1;
                            else if (v.y > n) v.x = n; 
                        }
                    // }
                    if (mat[v.x][v.y]) continue;
                    vis[v.x][v.y] = true;
                    Q.push(v);
                }
                else {
                    v.dist = u.dist + 1;
                    vis[v.x][v.y] = true;
                    Q.push(v);
                }
            }
        }
    }
    puts("Impossible");

    return ;
}
 
int main(int argc, char const *argv[])
{
    // freopen("test.in", "r", stdin);
    while (~scanf("%d%d", &n, &m)){
        int x, y, num, values;
        memset(vis, false, sizeof(vis));
        memset(mat, 0, sizeof(mat));
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            scanf("%d%d%d", &x, &y, &values);
            mat[x][y] = values;
        }
        scanf("%d%d%d%d", &x, &y, &pos_x, &pos_y);
        bfs(x, y);
    }
 
    return 0;
}
 