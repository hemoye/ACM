#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t, n;
	int arrAy[11];
	int ans(1);

	memset(arrAy, 0, sizeof(arrAy));

	for(int i = 1; i < 10; i++){
		ans *= i;
		arrAy[i] = ans;
	}
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 9; i > 0; i--){
			if (n >= arrAy[i]) 	n -= arrAy[i];
		}
		if (n)	puts("No");
		else 	puts("Yes");
	}

	return 0;
}