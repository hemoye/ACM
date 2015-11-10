#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100004;
int maxnum[MAXN][20], minnum[MAXN][20];

void rmq(int n)
{
	for (int j = 1; j < 20; j++){
		for (int i = 1; i <= n; i++){
			if (i + (1 << j) - 1 <= n){
				maxnum[i][j] = max(maxnum[i][j-1], maxnum[i+(1 << (j - 1))][j-1]);
				minnum[i][j] = min(minnum[i][j-1], minnum[i+(1 << (j - 1))][j-1]);
			}
		}
	}
	return ;
}

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int m, n, x, y;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &minnum[i][0]);
		maxnum[i][0] = minnum[i][0];
	}
	rmq(n);
	while (m--){
		scanf("%d%d", &x, &y);
		int k = (int)(log(y - x + 1.0 ) / log(2.0));
		printf("%d\n", max(maxnum[x][k], maxnum[y-(1<<k)+1][k]) - min(minnum[x][k], minnum[y-(1<<k)+1][k]));
	}

	return 0;
}	