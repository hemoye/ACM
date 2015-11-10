#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 24;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t, n, x;
	int arrAy[MAXN], stack[MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", arrAy + i);
		memset(stack, 0, sizeof(stack));
		stack[0] = 0;
		int top(0);
		for (int i = n; i > 0; i--){
			if (stack[top] < arrAy[i]) stack[++top] = arrAy[i];
			else {
				int temp = lower_bound(stack, stack + top, arrAy[i]) - stack;
				stack[temp] = arrAy[i];
			}
		}
		printf("%d\n", top);
	}

	return 0;
}
