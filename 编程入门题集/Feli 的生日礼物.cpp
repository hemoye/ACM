#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 4000;
using namespace std;


int main(int agrc, char *agrv[])
{
    int n;
    int arrAy[MAXN];

    while (~scanf("%d", &n)&&n){
        memset(arrAy, 0, sizeof(arrAy));
        arrAy[0] = 1;
        for ( int i = 2; i <= n; i++ ){
            int temp(0);
            for ( int j = 0; j < MAXN; j++ ){
                int c = arrAy[j] * i + temp;
                arrAy[j] = c % 10;
                temp = c / 10;
            }
        }
        for ( int i = 0; ; i++ ){
            if ( arrAy[i] ){
                printf("%d\n", arrAy[i]);
                break;
            }
        }
        /*
        int ans(1);
        for ( int i = 2; i <= n; i++ ){
            ans = (ans * n) % 10;
        }
        printf("%d\n", ans);
        */
    }

    return 0;
}
