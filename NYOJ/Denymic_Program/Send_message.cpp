#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 54;
int map[MAXN][MAXN];
int dp[MAXN*2][MAXN][MAXN];

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, row, line;

	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &row, &line);
		for (int i = 1; i <= row; i++){
			for (int j = 1; j <= line; j++) scanf("%d", &map[i][j]);
		}
		memset(dp, 0, sizeof(dp));
		int n = row + line;
		for (int k = 2; k <= n; k++){
			for (int i = 1; i <= row; i++){
				for (int j = 1; j <= row; j++){
					if (i != j && k >= i && k >= j){
						int t1 = max(dp[k-1][i][j], dp[k-1][i][j-1]);
						int t2 = max(dp[k-1][i-1][j], dp[k-1][i-1][j-1]);
						dp[k][i][j] = max(t1, t2) + map[i][k-i] + map[j][k-j];
					}
				}
			}
		}
		int ans = max(dp[n-1][row-1][row], dp[n-1][row][row-1]);
		printf("%d\n", ans);
	}

	return 0;
}	
