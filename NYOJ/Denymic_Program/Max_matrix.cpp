#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 104;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, r, c;
	int arrAy[MAXN][MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &r, &c);
		memset(arrAy, 0, sizeof(arrAy));
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				scanf("%d", &arrAy[i][j]);
				arrAy[i][j] += arrAy[i-1][j]; 	/*保存每一列的前i列的和*/
			}
		}
		int ans(arrAy[1][1]);
		for (int i = 1; i <= r; i++){
			for (int k = i; k <= r; k++){		/*枚举计算第i行到第k行之间的矩阵和*/
				for (int j = 1, temp(0); j <= c; j++){ /*转化为了一维，计算最大连续子段和*/
					if (temp < 0) temp = 0;
					temp += arrAy[k][j] - arrAy[i-1][j];
					ans = max(temp, ans);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
