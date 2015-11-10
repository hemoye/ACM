#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);

	int n, m, x;
	set<int> arrAy;
	set<int>::iterator it;

	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++){
		scanf("%d", &x);
		arrAy.insert(x);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		/*if (arrAy.count(x)) puts("YES");*/
		if (arrAy.find(x) != arrAy.end()) puts("YES");
		else puts("NO");
	}

	return 0;
}