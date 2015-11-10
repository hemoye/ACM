#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1004;

int main(int agrc, char *agrv[])
{
    int N;
    scanf("%d", &N);

    while (N--){
        int n;
        int arrAy[MAXN];

        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", arrAy + i);
        sort(arrAy, arrAy + n);
        for (int i = 0; i < n; i++) printf(0 == i ? "%d" : " %d", arrAy[i]);
        puts("");
    }

    return 0;
}
