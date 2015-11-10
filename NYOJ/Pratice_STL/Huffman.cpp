#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int> >pq;
const int MAXN = 12004;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t, n;
	long long arrAy[MAXN];
	
	scanf("%d", &t);
	while (t--){
		while (!pq.empty()) pq.pop();
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d", arrAy + i);
			pq.push(arrAy[i]);
		}
		long long ans(0);
		for (int i = 1; i < n; i++){
			long long temp = pq.top();
			pq.pop();
			temp += pq.top();
			ans += temp;
			pq.pop();
			pq.push(temp);
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}	