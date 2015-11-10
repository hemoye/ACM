#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 35665;

int main(int agrc, char *agrv[])
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
#endif
    int n;
    int arrAy[MAXN];

    while (~scanf("%d", &n)){
        memset(arrAy, 0, sizeof(arrAy));
        arrAy[MAXN-1] = 1;

        for ( int i = 1; i <= n; i++ ){
            int c(0);
            for ( int j = MAXN - 1; j > 0; j-- ){
                int temp = arrAy[j] * i + c;
                arrAy[j] = temp % 10;
                c = temp / 10;
            }
        }
        int len;
        for ( len = 0; !arrAy[len]; len++ );
        for ( int i = len; i < MAXN; i++ )  printf("%d", arrAy[i]);
        puts("");
    }

    return 0;
}
