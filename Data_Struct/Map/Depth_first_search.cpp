#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 27;
int n, m;
int pos[MAXN];
int arrAy[MAXN][MAXN];
bool vis[MAXN];
char str[MAXN];

void dfs(int cur)
{
	for (int i = 0; i < n; i++){
		if (vis[pos[i]] && arrAy[cur][pos[i]]){
			vis[pos[i]] = false;
			printf(" %c", str[pos[i]]);
			dfs(pos[i]);
		}
	}
}

void Sort()
{
	for (int i = 1; i < n; i++){
		for (int j = 0; j < n - i; j++){
			if (str[j] > str[j+1]){
				swap(str[j], str[j+1]);
				swap(pos[j], pos[j+1]);
			}
		}
	}
	return ;
}

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	while (~scanf("%d", &n)){
		char ch;
		scanf(" %s", str);
		for (int i = 0; i < n; i++) pos[i] = i;
		Sort();
		memset(arrAy, 0, sizeof(arrAy));
		memset(vis, true, sizeof(vis));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)	scanf("%d", &arrAy[i][j]);
		}
		scanf(" %c", &ch);
		int p = strchr(str, ch) - str;
		vis[p] = false;
		printf("%c", str[p]);
		dfs(p);
		puts("");
	}

	return 0;
}
