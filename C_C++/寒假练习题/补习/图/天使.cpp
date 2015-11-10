#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef struct node
{
    int x;
    int i,j;
    int step;
} node;
const int MAXN = 200 + 10;
node map[MAXN][MAXN];
int used[MAXN][MAXN];
int col[4][2] = {1,0,0,1,-1,0,0,-1};

int main( void )
{
    int n,m;
    while(cin>>n>>m)
    {
        queue <node> Q;
        memset(used,0,sizeof(used));
        memset(map,-1,sizeof(map));
        int i,j;
        char x[MAXN];
        int angle_x,angle_y;
        for (i = 0; i < n; i++)
        {
            scanf("%s",x);
            for (j = 0; j < m; j++)
            {
                map[i][j].step = 0;
                map[i][j].i = i;
                map[i][j].j = j;
                if (x[j] == '#')
                {
                    map[i][j].x = -1;
                }
                else if (x[j] == 'x')
                {
                    map[i][j].x = 2;
                }
                else if (x[j] == '.')
                {
                    map[i][j].x = 1;
                }
                else if (x[j] == 'a')
                {
                    map[i][j].x = 0;
                    angle_x = i;
                    angle_y = j;
                }
                else if (x[j] == 'r')
                {
                    map[i][j].x = -3;
                }
            }
        }
        Q.push(map[angle_x][angle_y]);
        used[angle_x][angle_y] = 1;
        int flag = 0;
        while (!Q.empty())
        {
            node N = Q.front();
            for (int k = 0; k < 4; k++)
            {
                if (N.i + col[k][0] >= 0 && N.i + col[k][0] < n && N.j + col[k][1] >= 0 && N.j + col[k][1] < m)
                {
                    if (map[N.i + col[k][0]][N.j + col[k][1]].x > 0 && used[N.i + col[k][0]][N.j + col[k][1]] == 0)
                    {
                        map[N.i + col[k][0]][N.j + col[k][1]].step = map[N.i + col[k][0]][N.j + col[k][1]].x + Q.front().step;
                        used[N.i + col[k][0]][N.j + col[k][1]] = 1;
                        Q.push(map[N.i + col[k][0]][N.j + col[k][1]]);
                    }
                    else if (map[N.i + col[k][0]][N.j + col[k][1]].x == -3)
                    {
                        flag = map[N.i][N.j].step + 1;
                        break;
                    }
                }
            }
            Q.pop();
            if (flag)
            {
                break;
            }
        }

        if (flag)
        {
            cout<<flag<<endl;
        }
        else
        {
            cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        }
    }
    return 0;
}
