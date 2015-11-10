#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 12;
int arrAy[MAXN], prev[MAXN];

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, n, m;

	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) arrAy[i] = i + 1;
		memcpy(prev, arrAy, sizeof(int) * m);
		for (int i = 0; i < m; i++) printf("%d", arrAy[i]);
		puts("");
		while (next_permutation(arrAy, arrAy + n)){
			if (memcmp(prev, arrAy, sizeof(int) * m)){
				for (int i = 0; i < m; i++) printf("%d", arrAy[i]);
				puts("");
				memcpy(prev, arrAy, sizeof(int) * m);
			}
		}
	}
	return 0;
}		