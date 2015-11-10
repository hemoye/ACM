#include <cstdio>

const int MAXN = 124;

int main(int agrc, char *agrv[])
{
    int n;
    int arrAy[MAXN][MAXN];

    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < MAXN; j++){
            arrAy[i][j] = 0;
            arrAy[i][1] = 1;
        }
    }
    arrAy[0][0] = 1;
    for (int i = 2; i < MAXN; i++){
        for (int j = 1; j <= i; j++){
            if (i - j <= j)  arrAy[i][j] = arrAy[i][j-1] + arrAy[i-j][i-j];
            else arrAy[i][j] = arrAy[i][j-1] + arrAy[i-j][j];
        }
    }
    while (~scanf("%d", &n))    printf("%d\n", arrAy[n][n]);

    return 0;
}
