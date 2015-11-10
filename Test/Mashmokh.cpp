#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 2000 + 4;
const int MOD = 1000000007;

int main(int argc, char const *argv[])
{
	int n, k;
	int arrAy[MAXN];

	while (~scanf("%d%d", &n, &k)){
		int ans(0);
		for (int i = 0; i < n; i++) arrAy[i] = i + 1;
		do {
			if (arrAy[0] >)
		} while (next_permutation(arrAy, arrAy + k));
	}

	do {
		for (int i = 1; i <= n; i++) printf("%d", arrAy[i]);
		puts("");
	} while (next_permutation(arrAy + 1, arrAy + n + 1));

	return 0;
}
