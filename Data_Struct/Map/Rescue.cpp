#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 400;

struct Node {
	int x, y;
	int dist;
} Queue[MAXN];

const int  dx[] = { -1, 1, 0, 0 };
const int  dy[] = { 0, 0, 1, -1 };
int n, m;
bool vis[MAXN][MAXN];
char map[MAXN][MAXN];

void bfs(int x, int y, int dist)
{
	int rear(0), front(-1);
	Queue[rear].x = x;
	Queue[rear].y = y;
	Queue[rear].dist = dist;
	vis[x][y] = true;
	while (front < rear){
		Node v, u = Queue[++front];
		for (int i = 0; i < 4; i++){
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];
			v.dist = u.dist;
			if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && !vis[v.x][v.y]){
				if (map[v.x][v.y] == '.') {
					vis[v.x][v.y] = true;
					v.dist = u.dist + 1;
					Queue[++rear] = v;
				}
				else if (map[v.x][v.y] == '#') continue;
				else if (map[v.x][v.y] == 'Q') {
					printf("%d\n", v.dist + 1);
					return ;
				}
				else {
					for (int p = 1; p <= n; p++){
						for (int q = 1; q <= m; q++){
							if (p == v.x && q == v.y) continue;
							if (map[p][q] == map[v.x][v.y]) {
								vis[v.x][v.y] = true;
								vis[p][q] = true;
								++rear;
								Queue[rear].x = p;
								Queue[rear].y = q;
								Queue[rear].dist = u.dist + 1;
							}
						}
					}
				}
			}
		}
	}
	puts("-1");

	return ;
}

int main(int argc, char const *argv[])
{
	int t, x, y;

	scanf("%d", &t);
	while (t--){
		memset(map, '#', sizeof(map));
		memset(vis, false, sizeof(vis));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				scanf(" %c", &map[i][j]);
				if ('L' == map[i][j]) {
					x = i;
					y = j;
				}
			}
		}
		bfs(x, y, 0);
	}

	return 0;
}
