#include <cstdio>
#include <cstring>

const int maxn = 1004;

int cmp(char *a, char *b)
{
	int lena = strlen(a);
	int lenb = strlen(b);
	if (lena > lenb) return 1;
	else if (lena < lenb) return -1;
	else return strcmp(a, b);
}

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	char a[maxn], b[maxn];

	while (~scanf("%s%s", a, b)){
		if (a[0] == '0' && b[0] == '0') break;
		if (a[0] == '-' && b[0] == '-'){
			if (cmp(b, a) == 1) puts("a>b");
			else if (cmp(a, b) == 0) puts("a==b");
			else puts("a<b");			
		}
		else if (a[0] == '-') puts("a<b");
		else if (b[0] == '-') puts("a>b");
		else {
			if (cmp(a, b) == 1) puts("a>b");
			else if (cmp(a, b) == 0) puts("a==b");
			else puts("a<b");
		}
	}

	return 0;
}