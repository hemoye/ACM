#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 104;
char str[MAXN];

int find(int left, int right)
{
	int ans(left);
	char temp(0);
	for (int i = left; i <= right; i++){
		if (str[i] > temp){
			temp = str[i];
			ans = i;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	// freopen("test.in", "r", stdin);
	int m, n;

	scanf("%d", &m);
	while (m--){
		scanf("%s%d", str, &n);
		int len = strlen(str) - n;
		int start(0);
		for (int i = 0; i < len; i++){
			int end = find(start, n+i);
			printf("%c", str[end]);
			start = end + 1;
		}
		puts("");
	}
	
	return 0;
}								