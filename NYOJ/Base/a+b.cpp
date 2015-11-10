#include <cstdio>
#include <algorithm>

using namespace std;

bool is_prime(int x)
{
	if (x <= 1)	return false;
	for (int i = 2; i * i <= x; i++){
		if (0 == x % i)	return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int n, m, ans;

	scanf("%d", &n);
	while (n--){
		scanf("%d", &m);
		for (int i = m, j = m; ; i--, j++){
			bool left = is_prime(i), right = is_prime(j);
			if (left && right){
				printf("%d %d\n", i, m - i);
				break;
			}
			else if (left){
				printf("%d %d\n", i, m - i);
				break;
			}
			else if (right){
				printf("%d %d\n", j, j - m);
				break;
			}
		}
	}

	return 0;
}