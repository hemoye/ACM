#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1004;

int map[MAXN][MAXN];
int vis[MAXN];

int dp(int i, int n)
{
    int &ans = vis[i];
    if (ans > 0) return ans;
    ans = 1;
    for (int j = 1; j <= n; j++){
        if (map[i][j]) ans = max(ans, dp(j, n) + 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /*freopen("test.in", "r", stdin);*/
    int t, n;
    int x[MAXN], y[MAXN];

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; i++){
            scanf("%d%d", &x[i], &y[i]);
            if (x[i] > y[i]) swap(x[i], y[i]);
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (x[i] > x[j] && y[i] > y[j]) map[i][j] = 1;
            }
        }
        int max_num(0);
        for (int i = 1; i <= n; ++i) max_num = max(max_num, dp(i, n));
        printf("%d\n", max_num);
    }

    return 0;
}
