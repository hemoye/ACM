#include <cstdio>
#include <cstring>

const int MAXN = 10004;

using namespace std;

int main(int agrc, char *agrv[])
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
#endif
    int n;
    char arrAy[MAXN];

    scanf("%d", &n);
    while (n--){
       scanf("%s", arrAy);
       int count(1);
       int len = strlen(arrAy);
       for (int i = 1; i <= len; i++){
            if (arrAy[i-1] == arrAy[i]){
                count++;
            }
            else {
                if (count > 1){
                    printf("%d%c", count, arrAy[i-1]);
                    count = 1;
                }
                else printf("%c", arrAy[i-1]);
            }
       }
       puts("");
    }

    return 0;
}
