#include <cstdio>

int main(int agrc, char *agrv[])
{
    int n;

    while (~scanf("%d", &n) && n){
        int ans(1);
        for (int i = 0; i < n; i++) ans = (ans * (n % 9)) % 9;
        ans = (0 == ans) ? 9 : ans;
        printf("%d\n", ans);
    }

    return 0;
}
