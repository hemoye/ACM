#include <stdio.h>
#define MAXN 240

void Sort( int , int * );

int main(void)
{
    int arrAy[MAXN], dis[MAXN];
    int board, length, num;
    int i, t;
    scanf("%d%d%d", &board, &length, &num );
    for( i = 0; i < num; i++ ){
        scanf("%d", &arrAy[i]);
    }
    Sort( num, arrAy );
    for( i = 1; i < num; i++ ){
        dis[i-1] = arrAy[i] - arrAy[i-1] - 1;
    }
    Sort( num - 1, dis );
    t = length - arrAy[0] +1;
    t = t - length + arrAy[num-1];
    for(i = 1; i < board; i++ ){
        t -= dis[num-1-i];
    }
    printf("%d\n", t);

    return 0;
}
void Sort( int n, int * p )
{
    int change = 1;
    int i, j, temp;
    for ( i = 1; i < n && change; i++ ){
        for ( j = 0; j < n - i; j++ ){
            if ( p[j] > p[j+1] ){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    return ;
}
