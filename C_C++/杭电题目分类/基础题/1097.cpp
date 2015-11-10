#include <cstdio>
#define  N 10
int main(int agrc, char *agrv[])
{
    int arrAy[N];
    int a, b;

    while (~scanf("%d%d", &a, &b)){
        arrAy[1] = a % 10;
        int i;
        for (i = 2; i < N; i++){
            arrAy[i] = arrAy[i-1] * (a % 10) % 10;
            if (arrAy[i] == arrAy[1]){
                arrAy[0] = arrAy[i-1];
                i--;
                break;
            }
        }
        printf("%d\n", arrAy[b%i]);
    }

    return 0;
}
