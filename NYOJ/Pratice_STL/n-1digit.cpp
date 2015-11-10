#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 12;

int main(int argc, char const *argv[])
{
	// freopen("test.in", "r", stdin);
	int n;
	char str[MAXN];

	scanf("%d", &n);
	while (n--){
		scanf("%s", str);
		int k;
		int len = strlen(str);
		for (k = 1; str[k] == '0' && k + 1 < len; k++) ;
		for ( ; k < len; k++) printf("%c", str[k]);
		puts("");
	}

	return 0;
}