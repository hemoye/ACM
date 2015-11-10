#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1004;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int t, n;
	int arrAy[MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)	scanf("%d", arrAy + i);
		sort(arrAy, arrAy + n);
		int ans(0);
		while (n > 3){
			ans += min(arrAy[0] + arrAy[1] * 2 + arrAy[n-1], arrAy[0] * 2 + arrAy[n-1] + arrAy[n-2]);
			n -= 2;
		}
		if (n == 1)	ans += arrAy[0];
		else if (2 == n)	ans += arrAy[1];
		else ans += arrAy[0] + arrAy[1] + arrAy[2];
		printf("%d\n", ans);
	}

	return 0;
}