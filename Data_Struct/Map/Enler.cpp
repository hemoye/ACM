#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1004;

/*
	所谓欧拉回路，既是每一个顶点都有一个入度和一个出度
	若度数不为2则不是回路
	以上有一个bug:有的点是不需要经过的，有的点是可以走
	多次的，只是线路(边)不能重复
*/

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int m, n;
	int x, y;
	int degree[MAXN];

	while (~scanf("%d", &n) && n){
		scanf("%d", &m);
		memset(degree, 0, sizeof(int)*(n+1));
		for (int i = 1; i <= m; i++){
			scanf("%d%d", &x, &y);
			degree[x]++;
			degree[y]++;
		}
		bool flag(true);
		for (int i = 1; i <= n; i++){
			if (degree[i] % 2){
				flag = false;
				break;
			}
		}
		if (flag) puts("1");
		else puts("0");
	}

	return 0;
}
