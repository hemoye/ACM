#include <cstdio>
#include <algorithm>

const int MAXN = 1000000 + 4;

char p[MAXN];
int f[MAXN];

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int n, kase(0);

	while (~scanf("%d", &n)){
		scanf("%s", p);
		f[0] = 0, f[1] = 0;
		for (int i = 1; i < n; i++) {
			int j = f[i];
			while (j && p[i] != p[j]) j = f[j];
			f[i+1] = (p[i] == p[j] ? j + 1 : 0);
		}
	}
	printf("Case #%d: \n", ++kase);
	for (int i = 2; i <= n; i++) {
		if (f[i] > 0 && i % (i - f[i]) == 0) printf("%d %d\n", i, i / (i - f[i]));
	}

	return 0;
}	
