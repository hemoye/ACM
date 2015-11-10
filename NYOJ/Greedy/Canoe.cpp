#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 400;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t, n, w;
	int arrAy[MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &w, &n);
		for (int i = 0; i < n; i++) scanf("%d", arrAy + i);
		sort(arrAy, arrAy + n);
		int ans(n-1), count(0);
		for (int i = 0; i <= ans && i < n; ){
			if (arrAy[i] + arrAy[ans] <= w) i++;
			count++;
			ans--;
		}
		printf("%d\n", count);
	}

	return 0;
}