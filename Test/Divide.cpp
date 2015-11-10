#include <cstdio>

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int w;

	while (~scanf("%d", &w)){
		if (w < 4 || (w % 2)) puts("NO");
		else puts("YES");
	}

	return 0;
}	
