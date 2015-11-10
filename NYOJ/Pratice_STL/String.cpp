#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1004;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int n;
	char child[11], dad[MAXN];

	scanf("%d", &n);
	while (n--){
		int count(0);
		scanf("%s%s", child, dad);
		char *pos = dad;
		while (true){
			 pos = strstr(pos, child);
			 if (pos == NULL) break;
			 pos = pos + 1;
			 count++;
		}
		printf("%d\n", count);
	}

	return 0;
}	