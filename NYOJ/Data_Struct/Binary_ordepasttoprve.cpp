#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 30;

void Ordepast_prev(char *orde, char *past, int len)
{
	if (len > 0){
		int p = strchr(orde, past[len-1]) - orde;
		printf("%c", past[len-1]);
		Ordepast_prev(orde, past, p);
		Ordepast_prev(orde + p + 1, past + p, len - p - 1);
	}
}

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/

	char orde[MAXN], past[MAXN];

	while (~scanf("%s%s", past, orde)){
		Ordepast_prev(orde, past, strlen(orde));
		puts("");
	}

	return 0;
}	
