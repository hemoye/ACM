#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5000 + 4;

struct Node {
	int w, l;
	bool operator < (const struct Node & s) const {
		if (s.l == l)	return s.w > w;
		return s.l > l;
	}
} arrAy[MAXN];

int main(int argc, char const *argv[])
{
	// freopen("test.in", "r", stdin);
	int t, n;
	int ans[MAXN];
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)	scanf("%d%d", &arrAy[i].l, &arrAy[i].w);
		sort(arrAy, arrAy + n);
		int count(0);
		for (int i = 0; i < n; i++){
			bool flag(true);
			for (int j = 0; j < count; j++){
				if (ans[j] <= arrAy[i].w){
					ans[j] = arrAy[i].w;
					flag = false;
					break;
				}
			}
			if (flag)	ans[count++] = arrAy[i].w;
		}
		printf("%d\n", count);
	}

	return 0;
}
