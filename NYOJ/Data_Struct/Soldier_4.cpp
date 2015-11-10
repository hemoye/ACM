#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000004;
int arrAy[MAXN];
int n, m;

int lowbit(int x)
{
	return x & (-x);
}
int sum(int x)
{
	int total(0);
	while (x <= n){
		total += arrAy[x];
		x += lowbit(x);
	}
	return total;
}
void update(int x, int num)
{
	while (x > 0){
		arrAy[x] += num;
		x -= lowbit(x);
	}
	return ;
}

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int x, y, num;
	char str[20];

	scanf("%d%d", &m, &n);
	while (m--){
		scanf("%s", str);
		if (0 == strcmp(str, "ADD")) {
			scanf("%d%d%d", &x, &y, &num);
			update(x-1, -num);
			update(y, num);
		}
		else {
			scanf("%d", &x);
			printf("%d\n", sum(x));
		}
	}

	return 0;
}	