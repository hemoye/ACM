#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 42;
int vis[maxn];

int dp(int x)
{
	if (vis[x]) return vis[x];
	if (1 == x) return vis[x] = 0;
	else if (2 == x) return vis[x] = 1;
	else if (3 == x) return vis[x] = 2;
	else return vis[x] = dp(x-1) + dp(x-2);
}

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, n;

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		dp(n);
		printf("%d\n", vis[n]);
	}

	return 0;
}	
