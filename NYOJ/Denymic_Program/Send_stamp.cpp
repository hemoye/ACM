#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1004;
int ans, Half;
int arrAy[MAXN];

void dp(int x, int cnt)
{
	if (0 == x){
		ans = max(ans, cnt);
		return ;
	}
	if (Half == ans) return ;
	if (cnt + arrAy[x] <= Half) dp(x-1, cnt + arrAy[x]);
	dp(x-1, cnt);
}

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int n, t;

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		int Max(0);
		for (int i = 1; i <= n; i++){
			scanf("%d", arrAy + i);
			Max += arrAy[i];
		}
		ans = 0;
		Half = Max / 2;
		dp(n, 0);
		printf("%d\n", Max - 2 * ans);
	}

	return 0;
}
