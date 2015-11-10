#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 104;
using namespace std;

int main(int agrc,char *agrv[])
{
    int n;

    while (~scanf("%d", &n)&&n){
        int number(0);
        int arrAy[MAXN][MAXN];
        for ( int i = 0; i < n; i++ ){
            int low(i), line(0);
            while (low >= 0){
                arrAy[low--][line++] = ++number;
            }
        }
        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < n - i; j++ )   printf("%d ", arrAy[i][j]);
            puts("");
        }
    }

    return 0;
}
