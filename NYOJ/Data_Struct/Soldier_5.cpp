#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000004;
long long arrAy[MAXN];
long long sum[MAXN];

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int n, c, q;
	int x, y, num;

	scanf("%d%d%d", &n, &c, &q);

	for (int i = 0; i <= n + 1;i++) sum[i] = arrAy[i] = 0;
	for (int i = 0; i < c; i++){
		scanf("%d%d%d", &x, &y, &num);
		arrAy[x-1] -= num;
		arrAy[y] += num;
	}
	for (int i = n; i >= 0; i--) arrAy[i] += arrAy[i+1];
	sum[0] = arrAy[0];
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + arrAy[i];
	while (q--){
		scanf("%d%d", &x, &y);
		num = (sum[y] - sum[x-1]) % 10003;
		printf("%d\n", num);
	}

	return 0;
}	
