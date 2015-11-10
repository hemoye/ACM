#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 22;
int num;
int legal[1<<MAXN];
int arrAy[MAXN][MAXN];
int dp[MAXN][1<<MAXN];

void init(int n)  									/*初始化、枚举出每一种可能的取值情况*/
{
	num = 0;
	for (int i = 0; i < (1 << n); i++){
		if ((i & (i << 1)) == 0) legal[num++] = i;
	}
	return ;
}
int get(int i, int j, int k)						/*累计第i行能取到的值*/
{
	int sum(0);
	while (j){
		if (j % 2) sum += arrAy[i][k];
		k--;
		j /= 2;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int n, ans;

	while (~scanf("%d", &n)){
		ans = 0;
		init(n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) scanf("%d", &arrAy[i][j]);
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < num; j++){
				if (0 == i){
					dp[i][j] = get(i, legal[j], n-1);
					ans = max(ans, dp[i][j]);
				}
				else {
					int temp(-1);
					for (int k = 0; k < num; k++){
						if ((legal[j] & legal[k]) == 0) temp = max(temp, dp[i-1][k]);
					}
					dp[i][j] = temp + get(i, legal[j], n-1);
					ans = max(ans, dp[i][j]);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
