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
            v.tim = u.tim - 1; // v.dist = u.dist + 1;Ҳ���޶���������Ӻã��ж��Ƿ��ܽ��������
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
�����Ĺ�����һ�δα�ħ��°��һ�δα���ʿ�ǾȻ���֮�󣬶��񣬲��ҵ�����һ�����������Ŀ��顣ħ���Ѿ�������Ϣ˵����Tʱ�̳Ե���������Ϊ������ҥ��˵�Թ�������Ҳ�ܳ������ϡ������Ĺ��������ļ���٣�����������ʿ�����ȹ�����������������ϰ��Ϊ�������������µ���ʿLJ�϶��ܽ����ȳ���
�־���̽����������������һ��������Թ���Թ��������S��0��0��0����������λ����P��ʾ��ʱ�մ������#��ʾ��ǽ��*��ʾ��ƽ����.��ʾ����ʿ��һ����ʱ�մ�����ͻᱻת����һ������λ�ã��������ת����λ����ǽ�Ļ�������ʿ�Ǿͻᱻײ������ʿ����һ����ֻ��ǰ�������ƶ���ÿ�ƶ�һ��1ʱ�̡������ƶ�ֻ��ͨ��ʱ�մ�������Ҳ���Ҫ�κ�ʱ�䡣


Input
����ĵ�һ��C��ʾ����C���������ݣ�ÿ���������ݵ�ǰһ������������N��M��T�� N��M�Թ��Ĵ�СN*M��1 <= N,M <=10)��T�������⡣����ȥ��ǰN*M��ʾ�Թ��ĵ�һ��Ĳ����������N*M��ʾ�Թ��ڶ���Ĳ��������


Output
�����ʿ���ܹ���Tʱ�����ҵ������������YES�������������NO����


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
