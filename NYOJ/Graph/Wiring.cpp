#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 504;
const int INF = 1 << 28;
int mat[MAXN][MAXN];
int e, v, ans;

void Prim()
{
	int lowcost[MAXN];
	int discost[MAXN];
	bool vis[MAXN];

	for (int i = 1; i <= e; i++){
		lowcost[i] = mat[1][i];
		discost[i] = 1;
		vis[i] = false;
	}
	vis[1] = true;
	for (int i = 1; i <= e; i++){
		int num(INF), k(1);
		for (int j = 1; j <= e; j++){
			if (num > lowcost[j] && !vis[j] && discost[j]){
				num = lowcost[j];
				k = j;
			}
		}
		if (!vis[k]) ans += num;
		vis[k] = true;
		for (int j = 1; j <= e; j++){
			if (lowcost[j] > mat[k][j] && !vis[j]){
				lowcost[j] = mat[k][j];
				discost[j] = k;
			}
		}
	}

	return ;
}

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t;

	scanf("%d", &t);
	while (t--){
		int x, y, n;
		memset(mat, 0, sizeof(mat));
		scanf("%d%d", &e, &v);
		for (int i = 1; i <= v; i++){
			scanf("%d%d%d", &x, &y, &n);
			mat[x][y] = mat[y][x] = n;
		}
		ans = INF;
		for (int i = 1; i <= e; i++) {
			scanf("%d", &x); 
			if (ans > x) ans = x;
		}
		Prim();
		printf("%d\n", ans);
	}	

	return 0;
}
