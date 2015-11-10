#include <stdio.h>
#define MAXN 100
#define MAX(a, b) (a) > (b) ? (a) : (b)
int v[MAXN], n, d[MAXN];
/*
	初始状态是S，目标状态是0
	当前状态i，每使用一个硬币j，状态便转移到i-Vj。
*/
int dp(int S)	//求得使用硬币次数
{
	if ( d[S] >= 0 )	return d[S];
	d[S] = 0;
	int i;
	for (i = 0; i < n; i ++) {
		if ( S >= v[i] ) {
			return d[S] = MAX(d[S], dp(S-v[i])+1);
		}
	}
	return d[S];
}
int main(void)
{
	int m;
	scanf("%d %d", &n, &m);
	int i;
	for (i = 0; i < n; i ++)	scanf("%d", &v[i]);
	memset(d, -1, sizeof(d));
	printf("%d\n", dp(m));
	return 0;
}
