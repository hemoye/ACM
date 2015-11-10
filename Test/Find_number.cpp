#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MOD = 12345;
const int MAXN = 1000 + 4;
int arrAy[MAXN][MAXN];

int find(int n, int number)
{
	int ret(0);
	if (number == 0) {
		ret = 8;
		for (int i = 1; i < n; i++) {
			ret = (ret * 9) % MOD;
		}
	}
	else {
		int x(1);
		for (int i = number; i < n; i++) {
			x = (x * 9) % MOD;
		}
		ret += (x * arrAy[n-1][number-1]) % MOD;
		if (n != number) {
			x = 8;
			for (int i = number + 1; i < n; i++){
				x = (x * 9) % MOD;
			}
			ret += (x * arrAy[n-1][number]) % MOD;
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int n;

	arrAy[0][0] = 1;
	for (int i = 0; i < MAXN; i++){
		arrAy[i][0] = arrAy[i][i] = 1;
		for (int j = 1; j < i; j++){
			arrAy[i][j] = (arrAy[i-1][j] + arrAy[i-1][j-1]) % MOD;
		}
	}

	while (~scanf("%d", &n)){
		int ans(0);
		for (int i = 0; i <= n; i += 2){
			ans = (ans + find(n, i)) % MOD;
		}
		printf("%d\n", ans);
	}

	return 0;
}
