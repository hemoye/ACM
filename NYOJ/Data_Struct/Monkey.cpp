#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1048600;
int arrAy[MAXN];

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int d, n;

	while (~scanf("%d%d", &d, &n) && d + n){
		int len = (int)pow(2.0, d);
		for (int i = 0; i <= len; i++) arrAy[i] = 0;
		int temp(1);
		for (int i = 0; i < n; i++){
			temp = 1;
			while (temp * 2 < len){
				if (arrAy[temp]){
					arrAy[temp] = 0;
					temp = temp * 2 + 1;
				}
				else {
					arrAy[temp] = 1;
					temp = temp * 2;
				}
			}
		}
		printf("%d\n", temp);
	}

	return 0;
}	