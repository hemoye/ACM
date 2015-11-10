#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 504;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, n;
	int map[MAXN][MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++) scanf("%d", &map[i][j]);
		}
		for (int k = 1; k <= n; k++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					if (map[i][k] && map[k][j]) map[i][j] = 1;
				}
			}
		}
		int ans(0);
		for (int i = 1; i <= n; i++){
				if (!map[i][i]) ans++;
		}
		printf("%d\n", n - ans);
	}

	return 0;
}
