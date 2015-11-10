#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int T;

	scanf("%d", &T);
	while (T--){
		long long n;
		scanf("%lld", &n);
		int i;
		long long x = sqrtl(n);
		for (i = 2; i * i <= x; i++){
			if (x % i == 0) break;
		}
		if (i * i > x && x * x == n && n > 1) puts("YES");
		else puts("NO");
	}

	return 0;
}
