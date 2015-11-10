#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 604;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t, n;
	float x;
	float arrAy[MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%f", &x);
			arrAy[i] = x + sqrt(x*x-1.0); 
		}
		sort(arrAy, arrAy + n);
		float ans(0);
		for (int i = n - 1; i >= 0; i--){
			ans += arrAy[i];
			if (ans - 20 >= 0.0000001){
				printf("%d\n", n - i);
				break;
			}
		}
	}

	return 0;
}	