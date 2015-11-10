#include <cstdio>

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int n;
	int max(0), min(10001);
	
	for (int i = 0; i < 5; i++){
		scanf("%d", &n);
		if (max < n)	max = n;
		if (min > n)	min = n;
	}
	printf("%d %d\n", min, max);

	return 0;
}