#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 10004;

struct Node {
	float left;
	float right;
	bool operator < (const struct Node & x) const {
		return x.left > left;
	}
} ;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t;
	int n, w, h, x, pos;
	struct Node arrAy[MAXN];

	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &w, &h);
		int num(0);
		for (int i = 0; i < n; i++){
			scanf("%d%d", &pos, &x);
			if (x * 2 >= h){
				float temp = sqrt(x*x - h*h/4.0);
				arrAy[num].left = pos - temp;
				arrAy[num++].right = pos + temp;
			}
		}
		sort(arrAy, arrAy + num);
		float end(0);
		int k(-1), count(0);
		while (end < w && arrAy[k+1].left <= end){
			float mmax(-1);
			for (int i = k+1; arrAy[i].left <= end && i < num; i++){
				if (mmax < arrAy[i].right){
					mmax = arrAy[i].right;
					k = i;
				}
			}
			end = mmax;
			count++;
		}
        printf("%d\n", end < w ? 0 : count);  
	} 

	return 0;
}