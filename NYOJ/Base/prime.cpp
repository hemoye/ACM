#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int n;
	int m, ans;

	scanf("%d", &n);
	while (n--){
		int count(0);
		scanf("%d%d", &ans, &m);
		while (ans >= m){
			count += ans / m;
			ans /= m;
		}
		printf("%d\n", count);
	}

	return 0;
}
