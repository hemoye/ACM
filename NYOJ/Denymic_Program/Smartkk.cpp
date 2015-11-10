#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 24;

int main(int argc, char const *argv[])
{
/*#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif*/
	
	int m, n;
	int arrAy[MAXN][MAXN];

	while (~scanf("%d%d", &n, &m)){
		memset(arrAy, 0, sizeof(arrAy));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				scanf("%d", &arrAy[i][j]);
				arrAy[i][j] += max(arrAy[i-1][j], arrAy[i][j-1]);
			}
		}
		printf("%d\n", arrAy[n][m]);
	}

	return 0;
}
