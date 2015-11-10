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
        �漰��С���ıȽ�ʱ�����Ҫ��ס��fabs����ȥ�Ƚϡ�
        ��ΪС���Ĵ洢���п��ܴ������
    */

    return 0;
}
