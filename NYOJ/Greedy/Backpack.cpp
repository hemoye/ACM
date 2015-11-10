#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
	int w, v;
	bool operator < (const struct Node & s) const {
		return s.v < v;
	}
} arrAy[20];

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t, n, m;

	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d%d", &arrAy[i].v, &arrAy[i].w);
		sort(arrAy, arrAy + n);
		int k(0), ans(0);
		while (m){
			if (arrAy[k].w <= m){
				m -= arrAy[k].w;
				ans += arrAy[k].w * arrAy[k].v;
			}
			else {
				ans += arrAy[k].v * m;
				m = 0;
			}
			k++;
		}
		printf("%d\n", ans);
	}

	return 0;
}