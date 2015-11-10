#include <cstdio>
#include <cmath>
#define  MAXN 500
#define  eps 1e-6

int main(int agrc, char agrv[])
{
    float test;
    float arrAy[MAXN] = {0};

    for (int i = 1; i < MAXN; i++)  arrAy[i] = arrAy[i-1] + 1.0/(i+1);
    while (~scanf("%f", &test) && fabs(test) >= eps){
        for (int i = 0; i < MAXN; i++){
            if (arrAy[i] > test || fabs(arrAy[i]-test) < eps){
                printf("%d card(s)\n", i);
                break;
            }
        }
    }
    /**
        涉及到小数的比较时，务必要记住用fabs函数去比较。
        因为小数的存储极有可能存在误差
    */

    return 0;
}
