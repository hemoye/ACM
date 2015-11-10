#include <stdio.h>
#include <string.h>
#define  MAXN 81

int n, k;
int total;
int vis[MAXN];

void dfs( int );

int main( void )
{
    while ( scanf("%d%d", &n, &k ) != EOF )
    {
        total = 10;
        printf("One of the anwser is : \n");
        dfs( 0 );
    }

    return 0;
}
void dfs( int cur )
{
    int i, j, v;

    if ( cur == n )
    {
        total--;
        for ( i = 0; i < n; i++ )
            printf("%c", 'A' + vis[i]);
        puts("");
        return 0;
    }
    for ( i = 0; i < k; i++ )
    {
        int ok = 1;
        vis[cur] = i;

        for ( j = 1; j * 2 <= cur + 1; j++ )
        {
            for ( v = 0; v < j; v++ )
                if ( vis[cur-v] != vis[cur-v-j] )
                    break;
            if ( v == j )
            {
                ok = 0;
                break;
            }
        }
        if ( ok && total  )
            dfs( cur + 1 );
    }
}
