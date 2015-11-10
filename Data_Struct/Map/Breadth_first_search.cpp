#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 27;
int n, m;
int arrAy[MAXN][MAXN];
bool vis[MAXN];
char str[MAXN];

void bfs(int cur)
{
	int queue[MAXN];
	int front(-1), rear(-1);
	queue[++rear] = cur;
	vis[cur] = false;
	while (front < rear){
		int k = queue[++front];
		printf(front ? " %c" : "%c", str[k]);
Flag:
		int x(-1);
		char c('Z'+1);
		for (int i = 0; i < n; i++){
			if (vis[i] && arrAy[k][i]){
				if (str[i] < c){
					x = i;
					c = str[i];
				}
			}
		}
		if (x >= 0){
			vis[x] = false;
			queue[++rear] = x;
			goto Flag;
		}
	}
	puts("");
	return ;
}
int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	while (~scanf("%d", &n)){
		char ch;
		scanf(" %s", str);
		memset(arrAy, 0, sizeof(arrAy));
		memset(vis, true, sizeof(vis));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)	scanf("%d", &arrAy[i][j]);
		}
		scanf(" %c", &ch);
		int p = strchr(str, ch) - str;
		bfs(p);
	}

	return 0;
}
