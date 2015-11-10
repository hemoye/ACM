#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 56;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int n;
	int arrAy[MAXN] = {0, 1, 1, 2};
	for (int i = 4; i < MAXN; i++) arrAy[i] = arrAy[i-1] + arrAy[i-3] + 1;
	while (~scanf("%d", &n)){
		printf("%d\n", arrAy[n]);
	}

	return 0;
}
