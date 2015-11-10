#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 0x7fff;
const int MAXN = 54;
int map[MAXN][MAXN];

int Prim(int n)
{
	int num(0);
	int lowcost[MAXN];
	int discost[MAXN];
	bool vis[MAXN];

	for (int i = 1; i <= n; i++){
		lowcost[i] = map[1][i];
		discost[i] = 1;
		vis[i] = true;
	}
	vis[1] = false;
	for (int i = 1; i <= n; i++){
		int ans(INF), k(1);
		for (int j = 1; j <= n; j++){
			if (ans > lowcost[j] && vis[j]){
				k = j;
				ans = lowcost[j];
			}
		}
		if (vis[k]) num += ans;
		vis[k] = false;
		for (int j = 1; j <= n; j++){
			if (lowcost[j] > map[k][j] && vis[j]){
				lowcost[j] = map[k][j];
				discost[j] = k;
			}
		}
	}
	return num;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int t, n;

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++) {
				scanf("%d", &map[i][j]);
				if (!map[i][j]) map[i][j] = INF;
			}
		}
		printf("%d\n", Prim(n));
	}

	return 0;
}
