#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000004;
int temp[MAXN], arrAy[MAXN];
long long ans;

void Merge(int low, int mid, int height)
{
	int k(low), i(low), j(mid);

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

void Merge_sort(int low, int height)
{
	if (low + 1 < height){
		int mid = (low + height) / 2;
		printf("%d\n", mid);
		Merge_sort(low, mid);
		Merge_sort(mid, height);
		Merge(low, mid, height);
	}
}

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int t, n;

	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", arrAy + i);
		ans = 0;
		Merge_sort(0, n);
		printf("%lld\n", ans);
	}

	return 0;
}	