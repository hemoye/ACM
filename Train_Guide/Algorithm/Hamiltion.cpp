#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 24;
bool vis[MAXN][MAXN];
int m, n, num;



int main(int argc, char const *argv[])
{

	while (~scanf("%d%d", &n, &m)){
		memset(vis, false, sizeof(vis));
		num = n * m - 1;
		Divide(0, 0, 0);
	}

	return 0;
}
