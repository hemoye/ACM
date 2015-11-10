#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1004;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/

	int n, m;
	int dp[MAXN], w[MAXN], v[MAXN];

	while (~scanf("%d%d", &n, &m)){
		if (n == 0 && m == 0) break;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) scanf("%d%d", &w[i], &v[i]);
		for (int i = 1; i <= n; i++){
			for (int j = m; j >= w[i]; j--){
				if (j >= w[i]) dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
			}
		}
		printf("%d\n", dp[m]);
	}

	return 0;
}
