#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1004;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int n;
	char str[MAXN];

	while (NULL != gets(str)){
		int len = strlen(str);
		for (int i = 0; i < len; i++){
			if (str[i] == 'y' && i + 1 < len && str[i+1] == 'o' && i + 2 < len && str[i+2] == 'u'){
				printf("we");
				i += 2;
			}
			else putchar(str[i]);
		}
		puts("");
	}

	return 0;
}	