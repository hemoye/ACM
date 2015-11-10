#include <stdio.h>
#include <string.h>
#define  MAXN 10001
#define  MAP 10

struct Node
{
    int x, y;
    int pre, t;
} Start;

const int help[4][2] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };//上下左右四个方位
int mat[MAP][MAP];
int vis[MAP][MAP];//观察图的走向
int m, n;

void bfs( int , int );

int main( void )
{
    int time;
    int i, j;

    scanf("%d", &time );

    while ( time-- )
    {
        scanf("%d%d", &m, &n );
        for ( i = 0; i < m; i++ )
            for ( j = 0; j < n; j++ )
            {
                scanf("%d", &mat[i][j] );
                if ( 2 == mat[i][j] )
                {
                    Start.x = i;
                    Start.y = j;
                    Start.pre = 1;
                    Start.t = 5;
                }
            }
        bfs( Start.x, Start.y );
    }
}
void bfs( int x, int y )
{
    struct Node Queue[MAXN];
    int front = 0, rear = 0;
    int i, j;

    Queue[rear++] = Start;
    while ( front < rear )
    {
        struct Node tp = Queue[front++];

//        printf("%d %d\n", tp.x, tp.y );
//        for ( i = 0; i < m; i++ )
//        {
//            for ( j = 0; j < n; j++ )
//                printf("%d", vis[i][j] );
//            puts("");
//        }
//        puts("");
//        getch();

        for ( i = 0; i < 4; i++ )
        {
            struct Node temp = tp;
            temp.x += help[i][0];
            temp.y += help[i][1];

            if ( 0 == mat[temp.x][temp.y] || temp.x < 0 || temp.x >= m || temp.y < 0 || temp.y >= n )
                continue;
//            vis[temp.x][temp.y] = 1;

            if ( 4 == mat[temp.x][temp.y] )
            {
                temp.t = 5;
                temp.pre++;
                Queue[rear++] = temp;
            }
            else if ( 3 == mat[temp.x][temp.y] && temp.t >= 0 )
            {
                printf("%d\n", temp.pre );
                return ;
            }
            else if ( 1 == mat[temp.x][temp.y] )
            {
                temp.pre++;
                temp.t--;
                Queue[rear++] = temp;
            }
        }
    }
    printf("-1\n");
    return ;
}
