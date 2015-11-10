#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 40;
int n, m, ans;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];

void bfs(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > m || mat[x][y] == '#' || vis[x][y]) return ;
	if (mat[x][y] == 'p') {
		ans++;
		mat[x][y] = '.';
	}
	vis[x][y] = true;
	bfs(x-1, y); bfs(x, y-1);
	bfs(x+1, y); bfs(x, y+1);
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &n, &m)){
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++) scanf(" %c", &mat[i][j]);
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if ('d' == mat[i][j]) {
					mat[i][j] = '.';
					bfs(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
