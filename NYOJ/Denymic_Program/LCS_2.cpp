#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100004;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int n, x;
	int stack[MAXN];

	while (~scanf("%d", &n)){
		int top(0);
		stack[0] = -0x7fffffff;
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			if (x > stack[top]) stack[++top] = x;
			else {
				int temp = lower_bound(stack, stack + top, x) - stack;
				stack[temp] = x; 
			}
		}
		printf("%d\n", top);
	}

	return 0;
}
