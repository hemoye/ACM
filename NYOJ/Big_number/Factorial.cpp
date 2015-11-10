#include <cstdio>
#include <cstring>

const int MAXN = 18000;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int n;
	int arrAy[MAXN];
	while (~scanf("%d", &n)){
		memset(arrAy, 0, sizeof(arrAy));
		arrAy[MAXN-1] = 1;
		for (int i = 1; i <= n; i++){
			int temp(0);
			for (int j = MAXN - 1; j > 0; j--){
				int x = arrAy[j] * i + temp;
				arrAy[j] = x % 10;
				temp = x / 10;
			}
		}
		int k;
		for (k = 0; !arrAy[k]; k++);
		for (int i = k; i < MAXN; i++) printf("%d", arrAy[i]);
		puts("");
	}
	
	return 0;
}