#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 24;
int n, ans, Half;
int sum[MAXN], arrAy[MAXN];

void dp(int x, int cnt)
{
	if (0 == x){
		ans = max(ans, cnt);
		return ;
	}
	if (ans == Half) return ;
	if (cnt + arrAy[x] <= Half) dp(x-1, cnt + arrAy[x]);
	dp(x-1, cnt);
}

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/

	int n;

	while (~scanf("%d", &n)){
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++){
			scanf("%d", arrAy + i);
			sum[i] += sum[i-1] + arrAy[i];
		}
		ans = 0;
		Half = sum[n] / 2;
		dp(n, 0);
		printf("%d\n", sum[n] - 2 * ans);
	}

	return 0;
}
