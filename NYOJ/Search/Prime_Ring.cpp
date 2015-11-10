#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 21;
int n, ans;
int vis[MAXN];
bool is_prime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0}; 

void slove(int cur)
{
	if (cur == n + 1 && is_prime[vis[1] + vis[n]]){
		ans++;
		for (int i = 1; i <= n; i++) printf(i == 1 ? "%d" : " %d", vis[i]);
		puts("");
		return ;
	}
	for (int i = 1; i <= n; i++){
		bool flag = true;
		vis[cur] = i;
		if (!is_prime[vis[cur] + vis[cur-1]]) flag = false;
		for (int j = 1; j < cur && flag; j++){
			if (vis[j] == vis[cur]) flag = false;
		}
		if (flag) slove(cur+1);
	}
	return ;
}

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int times(0);
	while (~scanf("%d", &n) && n){
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		ans = 0;
		printf("Case %d:\n", ++times);
		slove(2);
		if (!ans) puts("No Answer");
	}

	return 0;
}
