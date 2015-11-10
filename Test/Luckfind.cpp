#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1000000 + 4;
char str[MAXN];
int arrAy[MAXN];
int index;

void pre_deal(int len)
{
	index = 0;
	memset(arrAy, 0, sizeof(arrAy));
	if (str[0] == '4') arrAy[index]--;
	else arrAy[index]++;
	for (int i = 1; i < len; i++){
		if (str[i] == str[i-1]){
			if (arrAy[index] > 0) arrAy[index]++;
			else arrAy[index]--;
		}
		else {
			index++;
			if (str[i] == '4') arrAy[index]--;
			else arrAy[index]++;
		}
	}

	return ;
}

int main(int argc, char const *argv[])
{
	int n, m;

	while (~scanf("%d%d", &n, &m)){
		scanf("%s", str);
		pre_deal(n);
		while (m--){
			scanf("%s", str);
			if (str[0] == 'c') {

			}
			else {
				int x, y;
			}
		}
	}

	return 0;
}
	