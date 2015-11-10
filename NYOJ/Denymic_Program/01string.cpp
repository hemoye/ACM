#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 42;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, n;
	int arrAy[MAXN];
	arrAy[1] = 2;arrAy[2] = 3;

	for (int i = 3; i < MAXN; i++) arrAy[i] = arrAy[i-1] + arrAy[i-2];

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		printf("%d\n", arrAy[n]);
	}

	return 0;
}
