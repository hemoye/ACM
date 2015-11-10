#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100000 + 4;
int arrAy[MAXN];
int ctree[MAXN];
bool luck[MAXN];
char str[10];

bool judge(int n)
{
	for (int i = n; i; i /= 10) {
		if (!(i % 10 == 4 || i % 10 == 7)) return false;
	}
	return true;
}
int lowbit(int x)
{
	return x & (-x);
}
int sum(int x, int n)
{
	int ret(0);
	while (x > 0){
		ret += ctree[x];
		x -= lowbit(x);
	}
	return ret;
}
void add(int x, int n, int d)
{
	while (x <= n){
		ctree[x] += d;
		x += lowbit(x);
	}
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	for (int i = 1; i < MAXN; i++){
		luck[i] = judge(i);
	}
	memset(ctree, 0, sizeof(ctree));
	int n, m;
	while (~scanf("%d%d", &n, &m)){
		for (int i = 1; i <= n; i++) {
			scanf("%d", arrAy + i);
			if (luck[arrAy[i]]) add(i, n, 1);
		}
		while (m--){
			int l, r, d;
			scanf("%s", str);
			if (str[0] == 'a') {
				scanf("%d%d%d", &l, &r, &d);
				for (int i = l; i <= r; i++) {
					arrAy[i] += d;
					if (luck[arrAy[i]-d] && !luck[arrAy[i]]) {
						add(i, n, -1);		//如果加之前是，之后不是就要减1
					}
					else if (!luck[arrAy[i]-d] && luck[arrAy[i]]) {
						add(i, n, 1);		//如果加之前不是，之后是就要加1。 其他两种情况没有影响
					}
				}
			}
			else {
				scanf("%d%d", &l, &r);
				printf("%d\n", sum(r, n) - sum(l - 1, n));
			}
		}
	}

	return 0;
}
