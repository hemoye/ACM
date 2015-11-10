#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10004;

struct Node {
	int left, right;
	bool operator < (const struct Node & s) const {
		return s.right > right;
	}
} ;

int main(int argc, char const *argv[])
{
	freopen("test.in","r", stdin);
	int m, n;
	struct Node arrAy[MAXN];

	scanf("%d", &m);
	while (m--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)	scanf("%d%d", &arrAy[i].left, &arrAy[i].right);
		sort(arrAy, arrAy + n);
		int ans(0), count(1);
		for (int i = 1; i < n; i++){
			if (arrAy[ans].right < arrAy[i].left){
				ans = i;
				count++;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}