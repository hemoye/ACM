#include <cstdio>
#include <cstring>
#include <algorithm>

/*满足公式（4^k-1）/3， 但却是大数运算 --！*/

using namespace std;

const int MAXN = 1004;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, n;
	int arrAy[MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		memset(arrAy, 0, sizeof(arrAy));
		arrAy[MAXN-1] = 1;
		for (int i = 0; i < n; i++){				//求解得4^n的值
			int temp(0);
			for (int j = MAXN - 1; j > 0; j--){
				int x = arrAy[j] * 4 + temp;
				arrAy[j] = x % 10;
				temp = x / 10;
			}
		}
		int len;
		for (len = 0; !arrAy[len]; len++);
		for (int i = len; i < MAXN - 1; i++){
			if (arrAy[i] >= 3){
				arrAy[i+1] += (arrAy[i] % 3) * 10;
				arrAy[i] /= 3;
			}
			else {
				arrAy[i+1] += arrAy[i] * 10;
				arrAy[i] = 0;
			}
		}
		arrAy[MAXN-1] /= 3;
		if (arrAy[len]) printf("%d", arrAy[len]);
		for (int i = len + 1; i < MAXN; i++) printf("%d", arrAy[i]);
		puts("");
	}
	
	return 0;
}	