#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100004;
int n, c;
int arrAy[MAXN];

bool Search(int dist)
{
	int ans(1), cur(0);
	for (int i = 1; i < n; i++){
		if (arrAy[i] - arrAy[cur] >= dist){
			ans++;
			cur = i;
		}
		if (ans >= c) return true;
	}
	return false;
}

int solve(int left, int right)
{
	while (right >= left){
		int mid = (left + right) / 2;
		if (Search(mid)) left = mid + 1;
		else right = mid - 1;
	}
	return left - 1;
}

int main(int argc, char const *argv[])
{
	// freopen("test.in", "r", stdin);

	while (~scanf("%d%d", &n, &c)){
		for (int i = 0; i < n; i++) scanf("%d", arrAy + i);
		sort(arrAy, arrAy + n);
		printf("%d\n", solve(0, arrAy[n-1] - arrAy[0]));
	}

	return 0;
}