#include <stdio.h>
#define MAXN 100
#define MAX(a, b) (a) > (b) ? (a) : (b)
int v[MAXN], n, d[MAXN];
/*
	��ʼ״̬��S��Ŀ��״̬��0
	��ǰ״̬i��ÿʹ��һ��Ӳ��j��״̬��ת�Ƶ�i-Vj��
*/
int dp(int S)	//���ʹ��Ӳ�Ҵ���
{
	if ( d[S] >= 0 )	return d[S];
	d[S] = 0;
	int i;
	for (i = 0; i < n; i ++) {
		if ( S >= v[i] ) {
			return d[S] = MAX(d[S], dp(S-v[i])+1);
		}
	}
	return d[S];
}
int main(void)
{
	int m;
	scanf("%d %d", &n, &m);
	int i;
	for (i = 0; i < n; i ++)	scanf("%d", &v[i]);
	memset(d, -1, sizeof(d));
	printf("%d\n", dp(m));
	return 0;
}
