#include <stdio.h>
#include <stdlib.h>
#define  MAX 40

int n, Pos[MAX][MAX], vis[MAX][MAX];

void Creat( void );
void dfs( int , int );

int main( void )
{
    int time;

    scanf("%d", &time);

    while ( time-- )
    {
        memset( vis, 0, sizeof( vis ) );

        Creat();

        dfs( 0, 0 );

        if ( vis[3][3] )
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
void Creat( void )
{
    int i, j;

    printf("请输入迷宫的范围大小(n*n): ");
    scanf("%d", &n);

    char str[n+1];

    for ( i = 0; i < n; i++ ){
        scanf("%s", str);
        for ( j = 0; j < n; j++ )
            Pos[i][j] = str[j] - '\0';
    }

    return 0;
}
void dfs( int x, int y )
{
    if ( x < 0 || y < 0 || x >= n || y >= n )
        return ;

    if ( !vis[x][y] && Pos[x][y] ){
        vis[x][y] = 1;
        dfs( x, y + 1 );
        dfs( x, y - 1 );
        dfs( x + 1, y );
        dfs( x - 1, y );
    }

    return ;
}
