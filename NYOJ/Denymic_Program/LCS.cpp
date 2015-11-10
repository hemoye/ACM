#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1004;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int n;
	char str1[MAXN], str1[MAXN], stack[MAXN];

	scanf("%d", &n);
	while (n--){
		scanf("%s", str);
		int top(0);
		int len = strlen(str);
		stack[0] = 0;
		for (int i = 0; i < len; i++){
			if (str[i] > stack[top]) stack[++top] = str[i];
			else {
				int temp = lower_bound(stack, stack + top, str[i]) - stack;
				stack[temp] = str[i]; 
			}
		}
		printf("%d\n", top);
	}

	return 0;
}
