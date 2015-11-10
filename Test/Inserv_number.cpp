#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10000 + 4;
int arrAy[MAXN];
long long ans;

void Merge(int low, int mid, int height)
{
	int k(low), i(low), j(mid);
	int temp[MAXN];

	while(i < mid && j < height){
		if (arrAy[i] <= arrAy[j]) temp[k++] = arrAy[i++];
		else {
			temp[k++] = arrAy[j++];
			ans += mid - i;
		}
	}
	while (i < mid)	temp[k++] = arrAy[i++];
	while (j < height) temp[k++] = arrAy[j++];
	for (int i = low; i < height; i++)	arrAy[i] = temp[i];

	return ;
}

void Merge_sort(int low, int high)
{
	if (low + 1 < high){
		int mid = (low + high) / 2;
		Merge_sort(low, mid);
		Merge_sort(mid, high);
		Merge(low, mid, high);
	}
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int n;

	while (~scanf("%d", &n)){
		ans = 0;
		for (int i = 0; i < n; i++) scanf("%d", arrAy + i);
		Merge_sort(0, n);
		printf("%lld\n", ans);
	}

	return 0;
}
