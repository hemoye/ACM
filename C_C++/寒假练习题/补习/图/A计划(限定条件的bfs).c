#include <stdio.h>
#include <stdlib.h>
#define N 100
char map[2][N][N];
int vis[2][N][N], n, m, time;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
typedef struct node
{
    int x, y, z, tim;
} Node ;
Node q[N*N];
void bfs(int z, int x, int y)
{
    int front = 0, rear = 1;
    Node u, v;
    u.x = x;
    u.y = y;
    u.z = z;
    u.tim = time;
    vis[z][x][y] = 1;
    q[0] = u;
    while( front < rear )
    {
        u = q[front++];
        if( map[u.z][u.x][u.y] == 'P' )
        {
            printf("YES\n");
            return;
        }
        int i;
        for (i = 0; i < 4; i ++)
        {
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];
            v.z = u.z;
            v.tim = u.tim - 1; // v.dist = u.dist + 1;也行限定条件在外加好，判断是否能进入队列中
            if ( v.x >= 0 && v.y >= 0 && v.x < n && v.y < m && map[v.z][v.x][v.y]!='*' && !vis[v.z][v.x][v.y] && v.tim >= 0 )
            {
                if ( map[v.z][v.x][v.y] == '#' && !vis[v.z][v.x][v.y] )
                {
                    vis[v.z][v.x][v.y] = 0;
                    v.z = !u.z;
                }
                vis[v.z][v.x][v.y] = 1;
                q[rear++] = v;
            }
        }
    }
    printf("NO\n");
}
int main(void)
{
    int T, i, j, k;
    int x, y, z;
    scanf("%d", &T);
    while ( T -- )
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d %d %d", &n, &m, &time);
        for (i = 0; i < 2; i ++)
            for (j = 0; j < n; j ++)
                for (k = 0; k < m; k ++)
                {
                    scanf(" %c", &map[i][j][k]);
                    if ( map[i][j][k] == 'S' )
                    {
                        x = i;
                        y = j;
                        z = k;
                    }
                }
        for(i = 0; i < n; i ++)
            for(j = 0; j < m; j ++)
            {
                if( map[0][i][j] == '#' && map[1][i][j]=='#' )
                {
                    map[0][i][j] = '*';
                    map[1][i][j] = '*';
                }
                if( map[0][i][j] == '*' && map[1][i][j]=='#' )
                {
                    map[0][i][j] = '*';
                    map[1][i][j] = '*';
                }
                if( map[0][i][j] == '#' && map[1][i][j]=='*' )
                {
                    map[0][i][j] = '*';
                    map[1][i][j] = '*';
                }
            }
        bfs(x, y, z);
    }
    return 0;
}

/*
	Problem A

Time Limit : 3000/1000ms (Java/Other)   Memory Limit : 32768/32768K (Java/Other)
Total Submission(s) : 32   Accepted Submission(s) : 6
Problem Description
可怜的公主在一次次被魔王掳走一次次被骑士们救回来之后，而今，不幸的她再一次面临生命的考验。魔王已经发出消息说将在T时刻吃掉公主，因为他听信谣言说吃公主的肉也能长生不老。年迈的国王正是心急如焚，告招天下勇士来拯救公主。不过公主早已习以为常，她深信智勇的骑士LJ肯定能将她救出。
现据密探所报，公主被关在一个两层的迷宫里，迷宫的入口是S（0，0，0），公主的位置用P表示，时空传输机用#表示，墙用*表示，平地用.表示。骑士们一进入时空传输机就会被转到另一层的相对位置，但如果被转到的位置是墙的话，那骑士们就会被撞死。骑士们在一层中只能前后左右移动，每移动一格花1时刻。层间的移动只能通过时空传输机，且不需要任何时间。


Input
输入的第一行C表示共有C个测试数据，每个测试数据的前一行有三个整数N，M，T。 N，M迷宫的大小N*M（1 <= N,M <=10)。T如上所意。接下去的前N*M表示迷宫的第一层的布置情况，后N*M表示迷宫第二层的布置情况。


Output
如果骑士们能够在T时刻能找到公主就输出“YES”，否则输出“NO”。


Sample Input
1
5 5 14
S*#*.
.#...
.....
****.
...#.

..*.P
#.*..
***..
...*.
*.#..


Sample Output
YES

*/
