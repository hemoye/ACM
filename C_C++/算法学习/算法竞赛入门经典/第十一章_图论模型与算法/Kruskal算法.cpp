#include <cstdio>
#include <algorithm>
#define MAXN 100001
#define MAX 1000001
using namespace std;
int u[MAXN], v[MAXN], w[MAXN];
int n, m;
int p[MAX], r[MAXN];
int Find(int x)    { return p[x] == x ? x : p[x]=Find(p[x]); }
int cmp(const int i, const int j) {    return w[i] < w[j]; }
int Kruskal(void)
{
    int ans = 0;
    for (int i = 0; i < n; i ++)    p[i] = i;
    for (int i = 0; i < m; i ++)    r[i] = i;
    sort(r, r+m, cmp);
    int flag = 0;
    for (int i = 0; i < m; i ++) {
        int e = r[i];
        int x = Find(u[e]);
        int y = Find(v[e]);
        if ( x != y ) {
            ans += w[e];
            p[x] = y;
        }
        else { flag = 1; }
    }
    return ans;
}
int main(void)
{
    while ( ~scanf("%d %d", &n, &m) )
    for (int i = 0; i < m; i ++)    scanf("%d %d %d", &u[i], &v[i], &w[i]);
    printf("%d\n", Kruskal() );
    return 0;
}
