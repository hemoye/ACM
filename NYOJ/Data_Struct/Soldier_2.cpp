#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000004;
int arrAy[MAXN][2];
int len;

int lowbit(int x)
{
	return x & (-x);
}
int sum(int x)
{
	int total(0);
	while (x > 0){
		total += arrAy[x][1];
		x -= lowbit(x);
	}
	return total;
}
void create()
{
	for (int i = 1; i <= len; i++){
		for (int j = i - lowbit(i) + 1; j <= i; j++) arrAy[i][1] += arrAy[j][0];
	}
}
void update(int x, int num)
{
	while (x <= len){
		arrAy[x][1] += num;
		x += lowbit(x);
	}
	return ;
}

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int m, n, x, y;
	char str[20];

	scanf("%d%d", &n, &m);
	len = n;
	for (int i = 1; i <= n; i++) scanf("%d", &arrAy[i][0]);
	create();
	while (m--){
		scanf("%s%d%d", str, &x, &y);
		if (0 == strcmp(str, "ADD")) update(x, y);
		else printf("%d\n", sum(y) - sum(x-1));
	}

	return 0;
}	