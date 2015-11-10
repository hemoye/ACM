#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/

	stack<int> s[4];
	int t, n, m;
	scanf("%d", &t);
	while (t--){
		int x, y;
		bool flag(true);
		for (int i = 1; i < 4; i++){
			while (!s[i].empty()) s[i].pop();
		}
		scanf("%d%d", &m, &n);
		for (int i = m; i > 0; i--) s[1].push(i);
		while (n--){
			scanf("%d%d", &x, &y);
			if (!s[x].empty() && s[y].empty()){
				s[y].push(s[x].top());
				s[x].pop();
			}
			else if (!s[x].empty() && s[x].top() < s[y].top()){
				s[y].push(s[x].top());
				s[x].pop();
			}
			else flag = false;
		}
		if (flag) puts("legal");
		else puts("illegal");
	}

	return 0;
}	