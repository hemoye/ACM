#include <cstdio>
#include <algorithm>

using namespace std;

int Count(int n)
{
    int num(1);
    while (1 != n){
        if (n % 2)  n = n * 3 + 1;
        else n /= 2;
        num++;
    }
    return num;
}

int main(int agrc, char *agrv[])
{
    int m, n;

    while (~scanf("%d%d", &m, &n)){
        bool flage = true;
        int maxnum(0);
        if (n < m){
            swap(m, n);
            flage = false;
        }
        for (int i = m; i <= n; i++){
            maxnum = max(maxnum, Count(i));
        }
        if (flage) printf("%d %d %d\n", m, n, maxnum);
        else printf("%d %d %d\n", n, m, maxnum);
    }

    return 0;
}
