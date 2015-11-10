#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int> >pq;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int n, m;

	while (~scanf("%d", &n)){
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < n; i++){
			scanf("%d", &m);
			pq.push(m);
		}
		int ans(0);
		for (int i = 1; i < n; i++){
			m = pq.top();
			pq.pop();
			m += pq.top();
			pq.pop();
			pq.push(m);
			ans += m;
		}
		printf("%d\n", ans);
	}

	return 0;
}
