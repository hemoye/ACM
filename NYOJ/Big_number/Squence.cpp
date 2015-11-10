#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 104;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);

	int a[MAXN], b[MAXN], c[MAXN], sum[MAXN];
	char sa[MAXN], sb[MAXN], sc[MAXN];

	while (~scanf("%s%s%s", sa, sb, sc)){
		if (sa[0] == '0' && sb[0] == '0' && sc[0] == '0'){
			puts("0");
			continue;
		}
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		int x = MAXN-1, len = strlen(sa);
		while (len) a[x--] = sa[--len] - '0';
		x = MAXN - 1, len = strlen(sb);
		while (len) b[x--] = sb[--len] - '0';
		x = MAXN - 1, len = strlen(sc);
		while (len) c[x--] = sc[--len] - '0';
		for (int i = 0; i < 97; i++){
			memset(sum, 0, sizeof(sum));
			for (int j = MAXN - 1; j > 0; j--){
				sum[j] += a[j] + b[j] + c[j];
				sum[j-1] += sum[j] / 10;
				sum[j] %= 10;
			}
			for (int i = 0; i < MAXN; i++) a[i] = b[i];
			for (int i = 0; i < MAXN; i++) b[i] = c[i];
			for (int i = 0; i < MAXN; i++) c[i] = sum[i];
		}
		for (len = 0; !sum[len]; len++);
		for (int i = len; i < MAXN; i++) printf("%d", sum[i]);
		puts("");
	}

	return 0;
}