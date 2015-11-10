#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int agrc, char *agrv[])
{
    int x, y, m, n, L;
    while (~scanf("%d%d%d%d%d", &x, &y, &m, &n, &L)){
        int xx = x, yy = y, count(0);
        do {
            xx = (xx + m) % L;              //在圈内循环跳
            yy = (yy + n) % L;
            count++;
            if (xx==yy) break;
        }while (xx!=x && yy!=y);            //当两只青蛙同时跳到自己初始的位置时、代表它们永远不可能跳到同一个点

        if (xx==x&&yy==y)   puts("Impossible");
        else    printf("%d\n", count);
    }

    return 0;
}
