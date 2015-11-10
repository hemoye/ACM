#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 30004;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, n, money;
	int v[MAXN], p[MAXN], dp[MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &money, &n);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &p[i]);
		for (int i = 1; i <= n; i++){
			for (int k = money; k >= v[i]; k--){
				dp[k] = max(dp[k], dp[k-v[i]] + v[i] * p[i]);
			}
		}
		printf("%d\n", dp[money]);
	}

	return 0;
}
