#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int m, n;
int  vis[104][14];
char map[104][14];

int main(int argc, char const *argv[])
{
	int t;

	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", map[i]);
	}

	return 0;
}
