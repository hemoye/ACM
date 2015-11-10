#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 104;
int r, c;
int arrAy[MAXN][MAXN], dis[MAXN][MAXN];

int dfs(int x, int y, int num)
{
	if (x == 0 || y == 0 || x > r || y > c || arrAy[x][y] >= num) return 0;
	if (dis[x][y] != -1) return dis[x][y];
	int m = max(dfs(x+1, y, arrAy[x][y]), dfs(x-1, y, arrAy[x][y]));
	int n = max(dfs(x, y+1, arrAy[x][y]), dfs(x, y-1, arrAy[x][y]));
	dis[x][y] = max(m, n) + 1;
	return dis[x][y];
}

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t;

	scanf("%d", &t);
	while (t--){
		memset(dis, -1, sizeof(dis));
		memset(arrAy, 10004, sizeof(arrAy));
		scanf("%d%d", &r, &c);
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				scanf("%d", &arrAy[i][j]);
			}
		}
		int max_num(-1);
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++) max_num = max(max_num, dfs(i, j, 10004));
		}
		printf("%d\n", max_num);
	}	

	return 0;
}	
