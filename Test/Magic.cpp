#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int n;

	while (~scanf("%d", &n)){
		int i;
		for (i = n; i; i /= 10){
			if (!(i % 10 == 1 || i % 100 == 14 || i % 1000 == 144)) break;
		}
		if (i) puts("NO");
		else puts("YES");
	}

	return 0;
}
