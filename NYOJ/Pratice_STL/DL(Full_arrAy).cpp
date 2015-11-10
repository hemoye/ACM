#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 12;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, n;
	char arrAy[MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) arrAy[i] = i + 1;
		do{
			for (int i = 0; i < n; i++) printf("%d", arrAy[i]);
			puts("");
		}while (next_permutation(arrAy, arrAy + n));
	}

	return 0;
}
