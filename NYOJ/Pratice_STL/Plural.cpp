#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100004;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t, n, x;
	int arrAy[MAXN];

	scanf("%d", &t);
	while (t--){
		memset(arrAy, 0, sizeof(arrAy));
		scanf("%d", &n);
		while (n--){
			scanf("%d", &x);
			arrAy[x]++;
		}
		int pos(0), mmax(arrAy[0]);
		for (int i = 0; i < 100001; i++){
			if (mmax < arrAy[i]){
				pos = i;
				mmax = arrAy[i];
			}
		}
		if (mmax == arrAy[0]) printf("0 %d\n", arrAy[pos]);
		else printf("%d %d\n", mmax, arrAy[pos]);
	}

	return 0;
}	