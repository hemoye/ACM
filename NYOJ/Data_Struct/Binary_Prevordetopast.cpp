#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 30;

void Prevordertopast(char *prev, char *orde, int len)
{
	if (len > 0){
		int p = strchr(orde, prev[0]) - orde;
		Prevordertopast(prev + 1, orde, p);
		Prevordertopast(prev + 1 + p, orde + 1 + p, len - p - 1);
		printf("%c", prev[0]);
	}
}

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	char prev[MAXN], orde[MAXN];

	while (~scanf("%s%s", prev, orde)){
		Prevordertopast(prev, orde, strlen(prev));
		puts("");
	}

	return 0;
}	
