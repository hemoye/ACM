#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int m, n;

	while (~scanf("%d%d", &m, &n)){
		printf("%d\n", m * n / 2);
	}

	return 0;
}
