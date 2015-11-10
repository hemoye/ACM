#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1004;

struct Node{
	int id, length, width;
	bool operator < (const struct Node & s) const {
		if (s.id == id && s.length == length) return s.width > width;
		else if (s.id == id) return s.length > length;
		else return s.id > id;
	}
	bool operator != (const struct Node & s) const {
		return !(s.id == id && s.length == length && s.width == width);
	}
} arrAy[MAXN];

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, n;

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d%d%d", &arrAy[i].id, &arrAy[i].length, &arrAy[i].width);
			if (arrAy[i].length < arrAy[i].width) swap(arrAy[i].length, arrAy[i].width);
		}
		sort(arrAy, arrAy + n);
		printf("%d %d %d\n", arrAy[0].id, arrAy[0].length, arrAy[0].width);
		for (int i = 1; i < n; i++){
			if (arrAy[i] != arrAy[i-1]) printf("%d %d %d\n", arrAy[i].id, arrAy[i].length, arrAy[i].width);
		}
	}
	
	return 0;
}	
