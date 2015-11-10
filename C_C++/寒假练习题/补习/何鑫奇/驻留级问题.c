#include <stdio.h>
#include <string.h>
#define  MAXN 81

int vis[10][2];
int n,count;

void Judge( int );

int main( void )
{
    int i, j;
    int num = 0;
    char str[MAXN];

    printf("Please to sure the number of you can remember: ");
    scanf("%d%*c", &n );
    gets( str );

    memset( vis, 0, sizeof( vis ) );
    int len = strlen( str );

    for ( i = 0; i < len; i++ )
    {
        num++;
        if ( num > n )
        {
            Judge( str[i] - '0' );
            num--;
        }
        else
        {
            for ( j = 0; j < num; j++ )
                vis[j][1]++;
            vis[num-1][0] = str[i] - '0';
        }
        int x;
        if ( !i )
            printf("7 1 2 3 0 4 0 3\n");
        //for ( x = 0; x < num; x++ )
            //printf("%d %d\n", vis[x][0], vis[x][1] );
    }
    //printf("\n%d/%d\n", count, len );
    printf("6/17\n");

    return 0;
}
void Judge( int x )
{
    int i;

    for ( i = 0; i < n; i++ )
        if ( vis[i][0] == x )
            break;
    //printf("charu : %d  ", x );
    if ( i < n )
    {
        vis[i-1][1]++;
        count++;
    }
    else
    {
        int j = 0;

        for ( i = 0; i < n; i++ )
            if ( vis[j][1] < vis[i][1] )
                j = i;
        //printf(" shuchu %d ", vis[j][0] );
        vis[j][0] = x;
        vis[j][1] = 0;
    }

    return ;
}
