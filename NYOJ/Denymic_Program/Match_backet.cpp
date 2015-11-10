#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 104;
const int INF = 0x7fff;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t;
	int dis[MAXN][MAXN];
	char str[MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i <= len; i++){
			dis[i][i] = 1;
			for (int j = 0; j < i; j++) dis[i][j] = 0;
		}
		for (int k = 1; k < len; k++){
			for (int i = 0; i < len - k; i++){
				int j = i + k;
				dis[i][j] = INF;
				if ((str[i] == '[' && str[j] == ']') || (str[i] == '(' && str[j] == ')')){
					dis[i][j] = min(dis[i][j], dis[i+1][j-1]);
				}
				for (int x = i; x < j; x++){
					int temp = dis[i][x] + dis[x+1][j];
					dis[i][j] = min(dis[i][j], temp);
				}
			}
		}
		printf("%d\n", dis[0][len-1]);
	}

	return 0;
}	
