#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000004;
int arrAy[MAXN];

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int m, n;

	scanf("%d%d", &n, &m);
	arrAy[0] = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &arrAy[i]);
		arrAy[i] += arrAy[i-1];
	}
	int x, y;
	while (m--){
		scanf("%d%d", &x, &y);
		printf("%d\n", arrAy[y] - arrAy[x-1]);
	}

	return 0;
}	