#include <stdio.h>
#include <stdlib.h>
#define MAXN 50
int a[MAXN], n, C;
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main(void)
{
	scanf("%d %d", &n, &C);
	int i;
	for (i = 0; i < n; i ++)	scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);
	int count = 0, j = 0;
	i = 0;
	while ( i < n ) {
		if ( a[i] + a[n-1] > C ) {
			n --;
		}
		else {
			i ++;
			n --;
		}
		count ++;
	}
	printf("%d\n", count);
	return 0;
}
